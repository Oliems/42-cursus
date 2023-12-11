#include "NetworkManager.hpp"
#include "Server.hpp"
#include "def.hpp"
#include <arpa/inet.h>  /* inet_ntoa() */
#include <cerrno>       /* errno */
#include <cstring>      /* memset(), strerror() */
#include <iostream>     /* std::runtime_error */
#include <netdb.h>      /* hints, addrinfo */
#include <netinet/in.h> /* sin_addr */
#include <poll.h>       /* poll, pollfd */
#include <stdexcept>
#include <sys/socket.h> /* socket(2), send(2) */
#include <unistd.h>     /* close(2)*/

/*
 * The Unix program netcat (nc) can be used to test the server's message
 * handling. Use Ctrl-D to send partial messages. Warning, to send CR-LF
 * you need to press Ctrl-V Enter (CR-LF) and not just Enter (LF).
 */

/**
 * @brief Create a socket to listen for new connections.
 * @return -1 if an errror occured, otherwise returns the fd of the new socket.
 */
static int createListenSocket( char * port ) {
    int rv;
    int listener;
    struct addrinfo hints, *res, *p;

    /* Get a socket and bind it */
    std::memset( &hints, 0, sizeof( hints ) ); /* Make sure the struct is empty */
    hints.ai_family = AF_UNSPEC;               /* IPv4 or IPv6 */
    hints.ai_socktype = SOCK_STREAM;           /* TCP stream socket */
    hints.ai_flags = AI_PASSIVE;               /* Automatically fill in the IP */
    if ( ( rv = getaddrinfo( NULL, port, &hints, &res ) ) != 0 ) {
        /*
         * gai_strerror( rv ) should be used to transform the error code
         * into a string, but this function is forbidden by the subject
         */
        std::cerr << "getaddrinfo: " << rv << "\n";
        return -1;
    }

    for ( p = res; p != NULL; p = p->ai_next ) {
        if ( ( listener = socket( p->ai_family, p->ai_socktype, p->ai_protocol ) ) < 0 ) {
            continue;
        }

        /* Suppress "address already in use" message */
        int yes = 1;
        setsockopt( listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof( int ) );

        if ( bind( listener, p->ai_addr, p->ai_addrlen ) < 0 ) {
            close( listener );
            continue;
        }
        break;
    }
    freeaddrinfo( res ); /* free the linked list */

    /* If we got here, it means we didn't get bound */
    if ( p == NULL ) {
        return -1;
    }
    /* Start listening for incoming connections */
    if ( listen( listener, SOMAXCONN ) < 0 ) {
        return -1;
    }
    return listener;
}

void NetworkManager::setUp(char *port) {
    int listener = createListenSocket( port );
    if ( listener < 0 ) {
        throw std::runtime_error( "irc: error creating listening socket" );
    }
    std::memset( _buf, 0, sizeof( _buf ) );
    std::memset( _pollfds, 0, sizeof( _pollfds ) );
    _pollfds[ 0 ].fd = listener;
    _pollfds[ 0 ].events = POLLIN;
}

NetworkManager::NetworkManager( char * port , char *pass) : _fdcount(1), _server(Server(port, pass, *this)) {
}

NetworkManager::~NetworkManager() {
    /* Close any remaining fds */
    for ( int i = 0; i < _fdcount; i++ ) {
		close(_pollfds[i].fd);
    }
}

void NetworkManager::killClient( int fd ) {
    std::cerr << "irc: closed connection from " << _ips[ fd ] << " on socket " << fd << std::endl;

    /* Find the index corresponding to the fd */
    int index = 0;
    for ( ; _pollfds[ index ].fd != fd; index++ )
        ;

    /* Close the connection */
    close( fd );
    /* Delete all incomplete messages from this client */
    _incompleteMsg.erase( fd );
    /* Erase the client from the ip map */
    _ips.erase( fd );
    /* Remove the clients from pollfds */
    _pollfdsDel( index );
}

void NetworkManager::handleNewConnection() {
	int newfd;
	struct sockaddr_in *saddr;
	struct sockaddr_storage remoteaddr;
	socklen_t addrlen = sizeof( remoteaddr );


	if ( (newfd = accept( _pollfds[0].fd, reinterpret_cast<struct sockaddr *>(&remoteaddr), &addrlen ) ) < 0 ){
		throw std::runtime_error( std::string ("accept(): ")  + std::strerror( errno ));
		return ;
	}

	std::string ip = "hostname";
	if (remoteaddr.ss_family == AF_INET) {
		saddr = reinterpret_cast<struct sockaddr_in *>(&remoteaddr);
		ip = inet_ntoa( saddr->sin_addr );
	}
	_ips[ newfd ] = ip;

	std::cerr << "irc: new connection from " << ip << " on socket " << newfd << "\n";


	if (_fdcount < MAX_FDS) {
		_pollfdsAdd(newfd);
		return ;
	}

	/* If the maximum number of connections has been reached, send a message and close() */
	std::string errmsg = "Maximum number of connections reached. Please try again later.\r\n";
	if ( send( newfd, errmsg.c_str(), errmsg.size(), 0 ) < 0 ) {
		if ( errno != ECONNRESET && errno != EPIPE && errno != EBADF ) {
			throw std::runtime_error( std::string( "send(): " ) + std::strerror( errno ) );
		}
	}

	close( newfd );
}

void NetworkManager::handleEstablishedConnection(int pollIdx, std::deque<tMessage> &msgFrom) {
	(void)msgFrom;
	int sender_fd = _pollfds[ pollIdx ].fd;
	std::memset( _buf, 0, sizeof( _buf ) );

	int nbytes = recv( sender_fd, _buf, BUFFER_SIZE - 1, 0 );
	if ( nbytes <= 0 ) {
		/* Got error or connection closed by client */
		if ( nbytes == 0 ) {
			/* Connection closed by client, i.e the user pressed Ctrl-C */
			std::cerr << "irc: socket " << sender_fd << " was closed by client\n";
			std::string reason(" Disconnected");
			_server.closeConnection(sender_fd, reason);
			killClient(sender_fd);
			return ;
		}

		if ( errno != ECONNRESET && errno != EPIPE && errno != EBADF ) {
			throw std::runtime_error( std::string( "recv(): " ) + std::strerror( errno ) );
		}
		return ;
	}

	std::string const star = " * ";
	std::string const crlf = "\r\n";

	/* We managed to recv something from the client */
	/* End the string and add it to the map */
	std::string tmp(_buf);
	if (tmp.find(crlf) == std::string::npos)
		std::cout << "irc: buff " << sender_fd << " - " << tmp << std::endl;
	_buf[ nbytes ] = 0;
	_incompleteMsg[ sender_fd ] += std::string( _buf );
	/* Split the string into commands using delimiter "\r\n" */
	std::string & msgRef = _incompleteMsg[ sender_fd ];
	size_t posCrlf = 0;
	while ( _incompleteMsg.find(sender_fd) != _incompleteMsg.end() && ( posCrlf = msgRef.find( crlf ) ) != std::string::npos ) {
		tMessage tmp = { .fd = sender_fd, .msg = msgRef.substr( 0, posCrlf ) };
		if ( tmp.msg.compare( 0, 5, "USER " ) == 0 ) {
			/* Replace the unused '*' in the USER command with
			 * the IP address of the client  */
			size_t posStar = 0;
			if ( ( posStar = msgRef.find( star ) ) != std::string::npos ) {
				tmp.msg.replace( posStar + 1, 1, _ips[ tmp.fd ] );
			}
		}
		msgRef.erase( 0, posCrlf + crlf.length() );
		_server.processMessage(tmp);
	}
}

void NetworkManager::processMessage( std::deque<tMessage> & msgFrom, std::deque<tMessage> & msgTo ) {
	(void)msgTo;

	int poll_count = poll( _pollfds, _fdcount, POLL_TIMEOUT );
	if ( poll_count == 0 ) {
		/* Timeout has occured */
		return;
	} else if ( ( poll_count < 0 ) && ( gQuit == false ) ) {
		/* Error has occured */
		throw std::runtime_error( std::string( "poll(): " ) + std::strerror( errno ) );
	}

	/* Run through the existing connections looking for data to read */
	for ( int i = 0; i < _fdcount; i++ ) {


		if ( !(_pollfds[ i ].revents & POLLIN) )
			continue ;

		if ( _pollfds[ i ].fd == _pollfds[ 0 ].fd ) { /* listener socket */
			handleNewConnection();
			continue ;
		}

		handleEstablishedConnection(i, msgFrom);
	}
}

void NetworkManager::launch( void ) {
	std::deque<tMessage> msg;
	while (gQuit == false) {
		processMessage(msg, msg);
	}
}

void NetworkManager::_pollfdsAdd( int newfd ) {
    _pollfds[ _fdcount ].fd = newfd;
    _pollfds[ _fdcount ].events = POLLIN;
	_pollfds[ _fdcount ].revents = 0;
    _fdcount++;
}

void NetworkManager::_pollfdsDel( int i ) {
    /* Copy the last element over the element to delete */
    _pollfds[ i ] = _pollfds[ _fdcount - 1 ];
    _fdcount--;
}

#ifndef NETWORKMANAGER_HPP
# define NETWORKMANAGER_HPP

# include "def.hpp"
# include "utils.hpp"
# include "Server.hpp"
# include <deque>  /* std::deque */
# include <map>    /* std::map */
# include <poll.h> /* pollfd */
# include <string> /* std::string */

class NetworkManager {
public:
    NetworkManager();
    NetworkManager( char * port , char *pass);
    ~NetworkManager();

	void launch();
	void setUp(char *port);
    void processMessage( std::deque<tMessage> & msgFrom, std::deque<tMessage> & msgTo );
    void killClient( int fd );

private:
    int _fdcount;
    char _buf[ BUFFER_SIZE ];
    pollfd _pollfds[ MAX_FDS ];
    std::map<int, std::string> _incompleteMsg; /* map to store incomplete messages */
    std::map<int, std::string> _ips;           /* map to store the IP address for each fd */
	Server _server;

    void _pollfdsAdd( int newfd );
    void _pollfdsDel( int i );
	void handleNewConnection();
	void handleEstablishedConnection(int pollFdIdx, std::deque<tMessage> &msgFrom);

};

#endif

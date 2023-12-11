#include "NetworkManager.hpp"
#include <csignal>  /* signal() */
#include <cstdlib>  /* EXIT_SUCCESS, EXIT_FAILURE */
#include <ctime>    /* std::time */
#include <iostream> /* std::cerr */

bool gQuit = false;

void sigIntHandler( int signal ) {
    ( void )signal;
    std::cerr << "\nReceived SIGINT, exiting now...\n";
    gQuit = true;
}

int main( int argc, char ** argv ) {
    if ( argc != 3 || std::string( argv[ 1 ] ).empty() || std::string( argv[ 2 ] ).empty() ) {
        std::cerr << "Usage: ./ircserv <port> <password>\n";
        return EXIT_FAILURE;
    }
    int port = std::atoi( argv[ 1 ] );
    /* Ports in range [0-1023] require superuser privileges to use */
    if ( port < 1024 || port > 65535 ) {
        std::cerr << "Port " << port << " not in range [1024-65535]\n";
        return EXIT_FAILURE;
    }

    std::srand( static_cast<unsigned int>( std::time( NULL ) ) );
	NetworkManager ntm(argv[1], argv[2]);
    try {
		ntm.setUp(argv[1]);
    } catch ( const std::exception & e ) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    signal( SIGINT, sigIntHandler );
    /* Ignore any SIGPIPE in case the read end of the pipe was closed by client */
    signal( SIGPIPE, SIG_IGN );
    try {
		ntm.launch();
    } catch ( const std::exception & e ) {
        std::cerr << e.what() << '\n';
    }
    return EXIT_SUCCESS;
}

#include "Server.hpp"

void Server::pingMessage( tSocket const socket, std::string cmd, Client *clientPtr) {
	(void)clientPtr;
	
    std::vector<std::string> split = cmdSplit( cmd, " " );

    if ( split.size() == 2 ) {
        sendToFd( socket, std::string( "PONG " ) + split[ 1 ] );
    }
}

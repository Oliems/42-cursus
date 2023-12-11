#include "Server.hpp"
#include "NetworkManager.hpp"

void Server::quitMessage( tSocket socket, std::string cmd, Client * clientPtr) {
	(void)clientPtr;
	std::vector<std::string> splitCmd = cmdSplit( cmd, " " );
	std::string reason;

	for ( size_t i = 1; i < splitCmd.size(); i++ ) {
		reason += " " + splitCmd[ i ];
	}
	closeConnection(socket, reason);
	_ntm.killClient(socket);
}

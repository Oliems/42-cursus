#include "Server.hpp"
#include <cerrno>       /* errno */
#include <cstring>      /* memset(), strerror() */
#include <string>       /* std::string */
#include <sys/socket.h> /* socket(2), send(2) */
#include "NetworkManager.hpp"
#include "macro.hpp"
#include "utils.hpp"

void Server::passMessage( tSocket const socket, std::string cmd, Client *clientPtr ) {
	(void)clientPtr;

	std::map<tSocket, Client>::iterator clientIt= _clients.find(socket);

	if (clientIt != _clients.end()) {
		sendToFd(socket, ERR_ALREADYREGISTERED(clientIt->second.getNickName()));
		return ;
	}

    std::vector<std::string> split = cmdSplit( cmd, " " );

	if (split.size() < 2 ) {
		sendToFd(socket, ERR_NEEDMOREPARAMS("", "PASS"));
		_ntm.killClient(socket);
		return ;
	}

	if (split[1] != _passWord) {
		sendToFd(socket, ERR_PASSWDMISMATCH);
		_ntm.killClient(socket);
		return ;
	}

	_clients[socket] = Client(socket);

}

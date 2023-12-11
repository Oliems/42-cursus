#include "Server.hpp"
#include "Client.hpp"

#include <stack>
using std::map;
using std::string;
using std::vector;

void Server::deleteChannelFromMapIfEmpty( std::map<std::string, Channel>::iterator channelMapIt ) {
	if (channelMapIt->second.getNbUser() == 0) {
		std::cerr << "irc: "<< channelMapIt->second.getChannelName().asString() << " was cleaned because of inactivity" << std::endl;
		_channelMap.erase(channelMapIt);
	}
}

void Server::closeConnection(tSocket fd, std::string & reason) {
	map<tSocket, Client>::iterator clientIt = _clients.find(fd);

	if (clientIt == _clients.end()) {
		return ;
	}

	vector<string> arrChannelName = clientIt->second.getOutOfServer(reason);
	std::stack<string> stack;


	for (vector<string>::iterator it = arrChannelName.begin() ; it != arrChannelName.end() ; ++it) {
		map<string, Channel>::iterator chanIt = _channelMap.find(*it);
		deleteChannelFromMapIfEmpty(chanIt);
	}

	_nickMap.erase( clientIt->second.getNickName() );
	_clients.erase( fd );

}

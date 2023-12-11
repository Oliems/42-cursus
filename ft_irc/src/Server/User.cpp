#include "Server.hpp"

void Server::userMessage( tSocket const socket, std::string cmd, Client * clientPtr) {
	/* No need to check for NULL since the key `socket` must exist in _clients at this point */
	Client & client = *clientPtr;

	std::string realName;
	size_t colonPos = cmd.find( ':' );
	if ( colonPos == std::string::npos || colonPos == cmd.length() - 1 ) {
		/* Command does not contain a real name part or this part is empty */
		sendToFd( socket, ERR_NEEDMOREPARAMS( client.getNickName(), "USER" ) );
		return;
	}

	realName = cmd.substr( colonPos + 1 );
	cmd.erase( colonPos );

	/* The <realname> part has been erased so now we can split normally */
	std::vector<std::string> split = cmdSplit( cmd, " " );

	if ( split.size() != 4 || split[ 1 ].empty() || split[ 2 ].empty() || split[ 3 ].empty() ) {
		/* One of the parameter is missing */
		sendToFd( socket, ERR_NEEDMOREPARAMS( client.getNickName(), split[ 0 ] ) );
		return ;
	}
	if ( client.getUserName().empty() == false ) {
		sendToFd( socket, ERR_ALREADYREGISTERED( client.getNickName() ) );
		return ;
	} 

	client.setUserName( split[ 1 ] );
	client.setHostName( split[ 3 ] );
	client.setRealName( realName );
	welcomeMessage( socket, cmd );
}

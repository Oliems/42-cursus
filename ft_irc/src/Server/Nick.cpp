#include "Server.hpp"
#include <cctype> /* isalpha(), isalnum() */

/* Since the protocol does not specify, nicknames are treated as case-sensitive i.e john != John */
/* nickname = ( letter / special ) *8( letter / digit / special / "-" ) */
static bool nickIsValid( std::string nickName ) {
    size_t size = nickName.size();
    if ( size < 2 || size > 9 )
        return false;
    if ( !std::isalpha( nickName[ 0 ] ) && !isSpecial( nickName[ 0 ] ) )
        return false;
    for ( size_t i = 0; i < size; i++ ) {
        if ( !std::isalnum( nickName[ i ] ) && !isSpecial( nickName[ i ] ) && nickName[ i ] != '-' )
            return false;
    }
    return true;
}

void Server::nickMessage( tSocket socket, std::string cmd, Client * clientPtr) {
	/* No need to check for NULL since the key `socket' must exist in _clients at this point */
	std::vector<std::string> split = cmdSplit( cmd, " " );
	Client & client = *clientPtr;

	if ( split.size() != 2 || split[ 1 ].size() == 0 ) {
		sendToFd( socket, ERR_NONICKNAMEGIVEN( std::string( "Client" ) ));
		return ;
	} 

	if (( this->_nickMap.count( split[ 1 ] ) == 1 ) && ( this->_nickMap[ split[ 1 ] ]->getSocket() != client.getSocket() ) ) {
		/* Nickname already in use by another user */
		sendToFd( socket, ERR_NICKNAMEINUSE( split[ 1 ] ));
		return ;
	}

	if ( nickIsValid( split[ 1 ] ) == false ) {
		/* Nickname is not in a valid format */
		sendToFd( socket, ERR_ERRONEUSNICKNAME( split[ 1 ] ));
		return ;
	}

	if ( client.getNickName().empty() == false ) {
		/* Nickname change */
		sendToFd( socket, RPL_NICK_CHANGE( client.getNickName(), split[ 1 ], client.getUserName(), client.getHostName() ));
		for ( std::map<std::string, Channel *>::iterator it = client.getChannels().begin(); it != client.getChannels().end(); it++ ) {
			/* Alert clients from all channels the client is in that nickname has changed */
			it->second->sendMsgToAllChannelMember( RPL_NICK_CHANGE( client.getNickName(), split[ 1 ], client.getUserName(), client.getHostName() ), socket );
		}
		_nickMap.erase( client.getNickName() );
		client.setNickName( split[ 1 ] );
		_nickMap[split [1] ] = &client;
		return ;
	} 

	/* Nickname registration  */
	sendToFd( socket, RPL_NICK_REGISTER( split[ 1 ] ) );
	client.setNickName( split[ 1 ] );

	/* This handle the case where the first NICK message received a 433 reply */
	if ( client.getUserName().empty() == false ) {
		welcomeMessage( socket, cmd );
	}
	this->_nickMap[ split[ 1 ] ] = &client;
}

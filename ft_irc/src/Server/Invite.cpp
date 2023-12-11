#include "Server.hpp"

using std::map;
using std::string;
using std::vector;

void Server::inviteMessage( tSocket const socket, std::string cmd, Client * clientPtr) {

    Client & clientRef = *clientPtr;
    vector<string> parsedCmd = cmdSplit( cmd, ", " );

    if ( parsedCmd.size() < 3 ) {
        return ( sendToFd( socket, ERR_NEEDMOREPARAMS( clientRef.getNickName(), "INVITE" ) ) );
    }

    map<string, Client *>::iterator targetIt = _nickMap.find( parsedCmd[ 1 ] );

    if ( targetIt == _nickMap.end() ) {
        return ( sendToFd( socket, ERR_NOSUCHNICK( clientRef.getNickName(), parsedCmd[ 1 ] ) ) );
    }

    map<string, Channel>::iterator channelIt = _channelMap.find( parsedCmd[ 2 ] );

    if ( channelIt == _channelMap.end() ) {
        return ( sendToFd( socket, ERR_NOSUCHCHANNEL( parsedCmd[ 2 ] ) ) );
    }

    if ( channelIt->second.inviteUserToChannel( socket, targetIt->second->getSocket(), targetIt->second->getNickName() ) ) {
        sendToFd( socket, RPL_INVITING( parsedCmd[ 2 ], clientRef.getNickName(), parsedCmd[ 1 ] ) );
        sendToFd( targetIt->second->getSocket(), ":" + clientRef.getNickName() + " " + cmd );
    }
}

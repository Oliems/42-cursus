#include "Server.hpp"

using std::map;
using std::string;
using std::vector;

void Server::privmsgMessage( tSocket const socket, std::string cmd, Client * clientPtr) {

    Client & client = *clientPtr;
	string name = client.getNickName();

    vector<string> parsedCmd = cmdSplit( cmd, ", " );
    std::string msg;
    for ( unsigned int i = 2; i < parsedCmd.size(); i++ ) {
        msg += parsedCmd[ i ];
        if ( i + 1 < parsedCmd.size() )
            msg += " ";
    }
    if ( msg.length() == 0 ) {
        return ( sendToFd( socket, ERR_NOTEXTTOSEND( name ) ) );
    }

    if ( ( parsedCmd[ 1 ][ 0 ] == '#' || parsedCmd[ 1 ][ 0 ] == '&' ) ) {

		std::map<string, Channel>::iterator chanIt = _channelMap.find(parsedCmd[1]);

        if ( chanIt == _channelMap.end() ) {
            sendToFd( socket, ERR_NOSUCHNICK( name, parsedCmd[ 1 ] ) );
            return;
        }
        Channel & channel = chanIt->second;
        if ( channel.isOnChannel( client ) ) {
            cmd = moderate( socket, parsedCmd );
            channel.sendMsgToAllChannelMember( ":" + name + " " + cmd, socket );
			deleteChannelFromMapIfEmpty(chanIt);
        }
        return;
    }

    if ( parsedCmd[ 1 ] == "PING" ) {
        pingMessage( socket, cmd, clientPtr);
    }
    if ( parsedCmd[ 1 ] == "Hal" ) {
        botHandle( socket, parsedCmd );
        return;
    }

    map<string, Client *>::iterator receiverIt = _nickMap.find( parsedCmd[ 1 ] );
    if ( receiverIt == _nickMap.end() ) {
        sendToFd( socket, ERR_NOSUCHNICK( name, parsedCmd[ 1 ] ) );
        return;
    }
    sendToFd( receiverIt->second->getSocket(), ":" + name + " " + cmd + "\r\n" );
}

#include "Channel.hpp"
#include "NetworkManager.hpp"
#include "Server.hpp"

using std::map;
using std::string;
using std::vector;

static string _getTopic( string cmd );

void Server::topicMessage( tSocket const socket, std::string cmd, Client *clientPtr) {

    Client & clientRef = *clientPtr;

    vector<string> parsedCmd = cmdSplit( cmd, " " );

    unsigned int parsedCmdSize = parsedCmd.size();

    if ( parsedCmd.size() < 2 ) {
        return ( sendToFd( socket, ERR_NEEDMOREPARAMS( clientRef.getNickName(), "TOPIC" ) ) );
    }

    map<string, Channel>::iterator channelIt = _channelMap.find( parsedCmd[ 1 ] );

    if ( channelIt == _channelMap.end() ) {
        return ( sendToFd( socket, ERR_NOSUCHCHANNEL( parsedCmd[ 1 ] ) ) );
    }

    if ( parsedCmdSize == 2 ) {
        return ( channelIt->second.topicCmd( socket, clientRef.getNickName() ) );
    }

    string topic = _getTopic( cmd );
    if ( topic == ":" )
        return ( sendToFd( socket, ERR_NEEDMOREPARAMS( clientRef.getNickName(), "TOPIC" ) ) );

    return ( channelIt->second.topicCmd( socket, topic, clientRef.getNickName() ) );
}

static string _getTopic( string cmd ) {
    ( void )cmd;

    size_t pos = cmd.find( ":" );
    pos = cmd.find( ":", pos );
    if ( pos == cmd.npos || pos + 1 == cmd.npos )
        return ( string( ":" ) );
    return ( cmd.substr( pos + 1 ) );
}

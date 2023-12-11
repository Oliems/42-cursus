#include "Server.hpp"
#include <algorithm>

using std::string;
using std::vector;

void Server::partMessage( tSocket const socket, std::string cmd, Client *clientPtr ) {

    Client &clientRef = *clientPtr;

    vector<string> parsedCmd = cmdSplit( cmd, ", " );
    if ( parsedCmd.size() < 2 ) {
        sendToFd( socket, ERR_NEEDMOREPARAMS( clientRef.getNickName(), "PART" ) );
        return ;
    }

    vector<string> channelsToLeave;
    std::string reasonMsg;
    for ( unsigned int i = 1; i < parsedCmd.size(); i++ ) {
        if ( parsedCmd[ i ].c_str()[ 0 ] == ':' ) {
            while ( i < parsedCmd.size() ) {
                reasonMsg += " " + parsedCmd[ i ];
                i++;
            }
            break ;
        }
        channelsToLeave.push_back( parsedCmd[ i ] );
    }

    for ( vector<string>::iterator itVec = channelsToLeave.begin() ; itVec != channelsToLeave.end() ; ++itVec ) {
		std::map<string, Channel>::iterator foundIt = _channelMap.find(*itVec);
        if ( foundIt == _channelMap.end() ) {
            sendToFd( socket, ERR_NOSUCHCHANNEL(*itVec) );
            continue ;
        }
        clientRef.partChannel(*itVec, reasonMsg);
		deleteChannelFromMapIfEmpty(foundIt);
    }
}

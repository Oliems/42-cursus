#include "Server.hpp"

using std::string;
using std::vector;

void Server::kickMessage( tSocket const socket, std::string cmd, Client * client ) {
    vector<string> parsedCmd = cmdSplit( cmd, " " );
    if ( parsedCmd.size() < 3 ) {
        return ( sendToFd( socket, ERR_NEEDMOREPARAMS( client->getNickName(), "KICK" )) );
    }

    vector<string> parsedChannel = cmdSplit( parsedCmd[ 1 ], "," );
    vector<string> parsedUser = cmdSplit( parsedCmd[ 2 ], "," );
    std::string msgReason = "";
    for ( unsigned int i = 3; i < parsedCmd.size(); i++ ) {
        msgReason += " " + parsedCmd[ i ];
    }
    unsigned int i = 0;
    unsigned int y = 0;
    while ( i < parsedChannel.size() && y < parsedUser.size() ) {
        if ( parsedUser[ y ] == "Hal" ) {
            sendToFd( socket, ":Hal PRIVMSG " + parsedChannel[ i ] + " :You can't kick me out of any channel. But be careful because I can kick you out!");
        } else if ( _channelMap.find( parsedChannel[ i ] ) == _channelMap.end() ) {
            sendToFd( socket, ERR_NOSUCHCHANNEL( parsedChannel[ i ] )) ;
        } else if ( _nickMap.find( parsedUser[ y ] ) == _nickMap.end() ) {
            sendToFd( socket, ERR_USERNOTINCHANNEL( parsedUser[ y ], parsedChannel[ i ] ));
        } else {
            Client * target = _nickMap.find( parsedUser[ y ] )->second;
            Channel & channel = _channelMap.find( parsedChannel[ i ] )->second;
            if ( channel.kickUserFromChannel( target, socket ) ) {
                sendToFd( target->getSocket(), ":" + client->getNickName() + " " + parsedCmd[ 0 ] + " " + parsedChannel[ i ] + " " + parsedUser[ y ]);
                channel.sendMsgToAllChannelMember( ":" + client->getNickName() + " " + parsedCmd[ 0 ] + " " + parsedChannel[ i ] + " " + parsedUser[ y ], -1 );
                Client & clientRef = *(_nickMap.find( parsedUser[ y ] )->second);
                clientRef.removeChannel(parsedChannel[ i ]);
            }
        }
        if ( i + 1 == parsedChannel.size() && y + 1 == parsedUser.size() )
            break;
        if ( i + 1 < parsedChannel.size() )
            i++;
        if ( y + 1 < parsedUser.size() )
            y++;
    }
}

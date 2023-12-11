#include "Server.hpp"
#include "utils.hpp"

using std::exception;
using std::string;
using std::vector;

void Server::joinMessage( tSocket const socket, std::string cmd, Client * clientPtr) {

    Client & clientRef = *clientPtr;
    vector<string> parsedCmd = cmdSplit( cmd, " " );
    if ( cmd.size() < 2 ) {
        return ( sendToFd( socket, ERR_NEEDMOREPARAMS( clientRef.getNickName(), "JOIN" ) ) );
    }

    vector<string> vectorChannelsToJoin = cmdSplit( parsedCmd[ 1 ], "," );
    vector<string> password;
    if ( parsedCmd.size() > 2 ) {
        password = cmdSplit( parsedCmd[ 2 ], "," );
    }
    while ( password.size() < vectorChannelsToJoin.size() ) {
        password.push_back( "" );
    }
    for ( unsigned int i = 0; i < vectorChannelsToJoin.size(); i++ ) {

        if ( clientRef.getNbChannels() == MAX_CHAN_PER_USER ) {
            sendToFd( socket, ERR_TOOMANYCHANNELS( clientRef.getNickName(), vectorChannelsToJoin[ i ] ) );
            continue;
        }
        if ( _channelMap.find( vectorChannelsToJoin[ i ] ) == _channelMap.end() ) {
            if ( _channelMap.size() == MAX_CHAN_PER_SERV ) {
                sendToFd( socket, ERR_NOSUCHCHANNEL( vectorChannelsToJoin[ i ] ) );
                continue;
            }
            try {
                ChannelName channelName = ChannelName( vectorChannelsToJoin[ i ] );
                tClientRights clientRight = { .isOperator = true, .client = &clientRef, .insult = 0 };
                Channel newChannel = Channel( channelName, password[ i ] );
                newChannel.addUserToChannel( clientRight, password[ i ] );
                _channelMap.insert( std::make_pair( vectorChannelsToJoin[ i ], newChannel ) );
                Channel *channelref = &(_channelMap.find(vectorChannelsToJoin[i])->second);
                
                clientRef.addChannel(vectorChannelsToJoin[i], channelref);
            } catch ( exception & e ) {
                sendToFd( socket, e.what() );
                std::cerr << e.what() << std::endl;
            }
            continue;
        }

        Channel & channelToJoin = _channelMap.find( vectorChannelsToJoin[ i ] )->second;
        tClientRights clientRight = { .isOperator = false, .client = &clientRef, .insult = 0 };
        channelToJoin.addUserToChannel( clientRight, password[ i ] );
        clientRef.addChannel(vectorChannelsToJoin[i], & channelToJoin);
    }
}

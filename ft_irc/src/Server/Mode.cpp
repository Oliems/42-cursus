#include "Channel.hpp"
#include "NetworkManager.hpp"
#include "Server.hpp"
#include "def.hpp"
#include "macro.hpp"
#include "utils.hpp"
#include <cstdlib>

using std::map;
using std::string;
using std::vector;

void Server::modeMessage( tSocket const socket, std::string simplifiedCmd, Client *clientPtr ) {

	Client &client = *clientPtr;
    std::string const & clientName = client.getNickName();

    vector<string> parsedMessage = cmdSplit( simplifiedCmd, " " );
    int parsedMessageSize = parsedMessage.size();

    if ( parsedMessageSize < 2 ) {
        return ( sendToFd( socket, ERR_NEEDMOREPARAMS( clientName, "MODE" ) ) );
    }

    map<string, Channel>::iterator channelIt = _channelMap.find( parsedMessage[ 1 ] );

    if ( channelIt == _channelMap.end() ) {
        return ( sendToFd( socket, ERR_NOSUCHCHANNEL( parsedMessage[ 1 ] ) ) );
    }

    if ( parsedMessageSize == 2 ) {
        return ( sendToFd( socket, RPL_CHANNELMODEIS( clientName, channelIt->second.getChannelName().asString(), channelIt->second.listRights() ) ) );
    }

    tModeStruct toFill = {
        .setter = clientPtr,
        .settedOp = NULL,
        .passWord = "",
        .passWordOpt = false,
        .userLimit = -1,
        .topic = false,
        .invite = false,
        .setting = false
    };
    string options = parsedMessage[ 2 ];

    if ( fillTModeStruct( parsedMessage, toFill, socket, channelIt->second ) == false )
        return ( sendToFd( socket, ERR_NEEDMOREPARAMS( clientName, "MODE" ) ) );

    channelIt->second.modeCmd( socket, toFill, toFill.setting );
}

bool Server::fillTModeStruct( vector<string> & parsedMessage, tModeStruct & toFill, const tSocket sender,  Channel &channel ) {
    std::string & options = parsedMessage[ 2 ];

    string::iterator it = options.begin();

    if ( *it == '+' )
        toFill.setting = true;
    else if ( *it == '-' )
        toFill.setting = false;
    else
        return ( false );

    for ( it = ++it; it != options.end(); it++ ) {
        std::map<char, parsingModeFn>::iterator handler = _parsingModeMap.find( *it );
        if ( handler != _parsingModeMap.end() ) {
			tResponse response;
            if ((response = ( this->*( handler->second ) )( parsedMessage, toFill )) != NONE) {
				if (response == NEED_MORE_PARAMS) {
					std::cout << "this one " << std::endl;
					sendToFd(sender, ERR_NEEDMOREPARAMS_CHAN(_clients.find(sender)->second.getNickName(), "MODE", channel.getChannelName().asString()));
				} else {
					sendToFd(sender, ERR_NOSUCHNICK_CHAN(_clients.find(sender)->second.getNickName(), "MODE", parsedMessage[3], channel.getChannelName().asString()));
				}

			}
        } else {
            sendToFd( sender, ERR_UMODEUNKOWNFLAG( channel.getChannelName().asString(), _clients.find( sender )->second.getNickName(), *it ) );
        }
    }
    return ( true );
}

enum eResponse Server::iset( vector<string> & parsedMessage, tModeStruct & toFill ) {
    ( void )parsedMessage;
    toFill.invite = true;
    return ( NONE );
}

enum eResponse Server::tset( vector<string> & parsedMessage, tModeStruct & toFill ) {
    ( void )parsedMessage;
    toFill.topic = true;
    return ( NONE );
}

enum eResponse Server::kset( vector<string> & parsedMessage, tModeStruct & toFill ) {
    if ( parsedMessage.size() < 4 )
        return ( NEED_MORE_PARAMS );
    toFill.passWord = parsedMessage[ 3 ];
    parsedMessage.erase( parsedMessage.begin() + 3 );
    toFill.passWordOpt = true;
    return ( NONE );
}

enum eResponse Server::oset( vector<string> & parsedMessage, tModeStruct & toFill ) {
    if ( parsedMessage.size() < 4 )
        return ( NEED_MORE_PARAMS );
    std::map<std::string, Client *>::iterator settedIt = _nickMap.find( parsedMessage[ 3 ] );
    if ( settedIt == _nickMap.end() )
        return ( NO_SUCH_NICK );
    parsedMessage.erase( parsedMessage.begin() + 3 );
    toFill.settedOp = settedIt->second;
    return ( NONE );
}

enum eResponse Server::lset( vector<string> & parsedMessage, tModeStruct & toFill ) {
    if ( toFill.setting ) {
        if ( parsedMessage.size() < 4 && toFill.setting )
            return ( NEED_MORE_PARAMS);
        else {
            toFill.userLimit = std::strtol( parsedMessage[ 3 ].c_str(), NULL, 10 );
            parsedMessage.erase( parsedMessage.begin() + 3 );
        }
    } else
        toFill.userLimit = 0;
    return ( NONE );
}

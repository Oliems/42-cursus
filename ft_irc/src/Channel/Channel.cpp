#include "Channel.hpp"
#include "Client.hpp"
#include "NetworkManager.hpp"
#include "macro.hpp"
#include "utils.hpp"
#include <algorithm>
#include <ostream>

using std::map;
using std::string;

Channel::Channel( ChannelName channelName, std::string pass )
    : _clients( std::map<tSocket, tClientRights>() )
    , _passWord( pass )
    , _channelName( channelName )
    , _topic( "" )
    , _nbOperator( 1 )
    , _userLimit( MAX_USER_PER_CHAN ) {
    if ( pass.size() != 0 ) {
        _mode = PASS_NEEDED;
        _passWord = pass;
    } else
        _mode = DEFAULT;
}

Channel::~Channel() {
}

int Channel::getNbUser() const {
    return ( _clients.size() );
}

tClientRights Channel::getClientRights( tSocket socket ) const {
    return ( _clients.find( socket )->second );
}

std::string Channel::getPassWord( void ) const {
    return ( _passWord );
}

ChannelName Channel::getChannelName( void ) const {
    return ( _channelName );
}

std::string Channel::getTopic( void ) const {
    return ( _topic );
}

void Channel::setPassword( std::string pass ) {
    this->_passWord = pass;
}

string Channel::listClients( void ) const {
    string retVal( "@Hal" );

    for ( map<tSocket, tClientRights>::const_iterator it = _clients.begin(); it != _clients.end(); it++ ) {
        if ( it != _clients.end() ) {
            retVal += " ";
        }

        if ( it->second.isOperator )
            retVal += "@";
        retVal += it->second.client->getNickName();
    }
    return ( retVal );
}

void Channel::addUserToChannel( tClientRights & clientRight, std::string pass) {

    tSocket socket = clientRight.client->getSocket();
    std::string channelName = _channelName.asString();

    if ( _mode & PASS_NEEDED && pass != _passWord ) {
        return ( sendToFd( socket, ERR_BADCHANNELKEY( clientRight.client->getNickName(), channelName )) );
    }

    if ( _mode & INVITE_ONLY && _invited.find( socket ) == _invited.end() )
        return ( sendToFd( socket, ERR_INVITEONLYCHAN( channelName )) );

    if ( _mode & LIMIT_USERS && _clients.size() >= _userLimit ) {
        return ( sendToFd( socket, ERR_CHANNELISFULL( clientRight.client->getNickName(), channelName )) );
    }

    _clients[ socket ] = clientRight;
    sendMsgToAllChannelMember( RPL_JOIN( clientRight.client->getNickName(), channelName ), -1 );
    if ( _clients.size() == 1 )
        _nbOperator++;

    sendToFd( socket, RPL_NAMREPLY( clientRight.client->getNickName(), this->_channelName.asString(), this->listClients() ));
    if ( _topic.size() > 0 ) {
        sendToFd( socket, RPL_TOPIC( clientRight.client->getNickName(), channelName, _topic ));
    }
    if ( _mode ) {
        sendToFd( socket, RPL_CHANNELMODEIS( clientRight.client->getNickName(), channelName, listRights() ));
    }
}

bool Channel::kickUserFromChannel( Client * target, tSocket client) {

    std::string channelName = _channelName.asString();

    if ( _clients.find( client ) == _clients.end() && client != HAL ) {
        sendToFd( client, ERR_NOTONCHANNEL( target->getNickName(), channelName ));
        return ( false );
    }
    if ( _clients.find( target->getSocket() ) == _clients.end() ) {
        sendToFd( client, ERR_USERNOTINCHANNEL( target->getNickName(), channelName ));
        return ( false );
    }
    if ( client != HAL && !_clients.find( client )->second.isOperator ) {
        sendToFd( client, ERR_CHANOPRIVSNEEDED( target->getNickName(), channelName ));
        return ( false );
    }
    if ( client == HAL ) {
        suppressUserFromChannel(HAL, target->getSocket());
        return ( true );
    }
    suppressUserFromChannel( client, target->getSocket());
    return ( true );
}

int Channel::incrementInsult( tSocket socket ) {
    _clients.find( socket )->second.insult++;
    return ( _clients.find( socket )->second.insult );
}

bool Channel::isOnChannel( Client client ) {

    if ( _clients.find( client.getSocket() ) == _clients.end() && client.getSocket() != HAL ) {
        sendToFd( client.getSocket(), ERR_NOTONCHANNEL( client.getNickName(), _channelName.asString() ));
        return false;
    }
    return true;
}

void Channel::sendMsgToAllChannelMember( std::string msg, tSocket sender ) {
    std::map<tSocket, sClientsRights>::iterator it = _clients.find(sender);
    if ( it != _clients.end() && sender != -1 && it->second.insult >= 3 ) {
        sendMsgToAllChannelMember( RPL_HAL_KICK( _channelName.asString(), it->second.client->getNickName() ), -1 );
		it->second.client->removeChannel(_channelName.asString());
        kickUserFromChannel( it->second.client, -1 );
        return;
    }
    for ( std::map<tSocket, tClientRights>::iterator it = _clients.begin(); it != _clients.end(); it++ ) {
        if ( it->first == sender )
            continue;
        sendToFd( it->first, msg);
    }
}

void Channel::sendMsgToAllByNick( std::string first, std::string second ) const {
    for ( std::map<tSocket, tClientRights>::const_iterator it = _clients.begin(); it != _clients.end(); it++ ) {
        Client * clientRef = it->second.client;
        sendToFd( clientRef->getSocket(), first + " " + clientRef->getNickName() + " " + second );
    }
}

void Channel::suppressUserFromChannel( tSocket sender, tSocket target) {
    if ( _clients.find( target )->second.isOperator == false ) {
        _clients.erase( target );
        return ;
    }
    _clients.erase( target );
    _nbOperator--;
    if ( _clients.size() >= 1 && _nbOperator <= 1 ) {
        _clients.begin()->second.isOperator = true;
        ++_nbOperator;
        std::string newOperatorNick = _clients.begin()->second.client->getNickName();
        sendMsgToAllChannelMember( ":IRC MODE " + _channelName.asString() + " +o " + newOperatorNick, sender );        
    }
}

bool Channel::inviteUserToChannel( tSocket sender, tSocket target, std::string nick ) {

    std::string channelName = _channelName.asString();

    if ( _clients.find( sender ) == _clients.end() ) {
        sendToFd( sender, ERR_NOTONCHANNEL( _clients.find( sender )->second.client->getNickName(), channelName ));
        return ( false );
    }
    tClientRights rightsClient = _clients.find( sender )->second;
    if ( !rightsClient.isOperator ) {
        sendToFd( sender, ERR_CHANOPRIVSNEEDED( _clients.find( sender )->second.client->getNickName(), channelName ));
        return ( false );
    }
    _invited[ target ] = nick;
    return ( true );
}

void Channel::topicCmd( tSocket setter, std::string topic, string const & nick ) {

    map<tSocket, tClientRights>::iterator setterRightsIt = _clients.find( setter );

    if ( setterRightsIt == _clients.end() ) {
        return ( sendToFd( setter, ERR_NOTONCHANNEL( nick, this->_channelName.asString() )) );
    }

    tClientRights & setterRights = setterRightsIt->second;

    if ( _mode & TOPIC_FR_OP && setterRights.isOperator == false ) {
        return ( sendToFd( setter, ERR_CHANOPRIVSNEEDED( setterRights.client->getNickName(), _channelName.asString() )) );
    }

    _topic = topic;

    if ( topic.size() != 0 )
        sendMsgToAllByNick( ":IRC 332 ", _channelName.asString() + " :" + _topic );
    else
        sendMsgToAllChannelMember(  RPL_NOTOPIC( _channelName.asString() ), -1 );
}

void Channel::topicCmd( tSocket setter, std::string nick ) {
    if ( _topic.size() == 0 )
        sendToFd( setter, RPL_NOTOPIC( _channelName.asString() ));
    else
        sendToFd( setter, ":IRC 332 " + nick + " " + _channelName.asString() + " :" + _topic);
}

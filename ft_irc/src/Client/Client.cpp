#include "Client.hpp"
#include "macro.hpp"
#include "utils.hpp"

Client::Client()
    : _socket( -1 )
    , _nickName( "" )
    , _hostName( "" )
    , _userName( "" )
    , _realName( "" )
    , _moderate( 0 ) {
}

Client::Client( int fd )
    : _socket( fd )
    , _nickName( "" )
    , _hostName( "" )
    , _userName( "" )
    , _realName( "" )
    , _moderate( 0 ) {
}

void Client::setNickName( std::string nickName ) {
    this->_nickName = nickName;
}

void Client::setHostName( std::string hostName ) {
    this->_hostName = hostName;
}

void Client::setUserName( std::string userName ) {
    this->_userName = userName;
}

void Client::setRealName( std::string realName ) {
    this->_realName = realName;
}

tSocket Client::getSocket( void ) const {
    return ( this->_socket );
}

int Client::getNbChannels( void ) const {
    return ( this->_channels.size() );
}

std::string const & Client::getNickName( void ) const {
    return this->_nickName;
}

std::string const & Client::getHostName( void ) const {
    return this->_hostName;
}

std::string const & Client::getUserName( void ) const {
    return this->_userName;
}

std::string const & Client::getRealName( void ) const {
    return this->_realName;
}

std::map<std::string, Channel *> & Client::getChannels() {
    return this->_channels;
}

int Client::getModerate() const {
    return ( _moderate );
}

void Client::setModerate( int num ) {
    _moderate = num;
}

bool Client::isRegistered( void ) {
    if ( !this->_nickName.empty() && !this->_hostName.empty() && !this->_userName.empty() && !this->_realName.empty() && this->_socket != -1 ) {
        return true;
    }
    return false;
}

void Client::addChannel( std::string channelName, Channel *channel ) {
    _channels.insert( std::pair<std::string, Channel *>(channelName, channel) );
}

void Client::removeChannel( std::string channel ) {
    _channels.erase(channel);
}

std::vector<std::string> Client::getOutOfServer( std::string &msg) {
	std::vector<std::string> retVal;

    for (std::map<std::string, Channel *>::iterator it = _channels.begin() ; it != _channels.end() ; it++) {
		retVal.push_back(it->second->getChannelName().asString());
		it->second->sendMsgToAllChannelMember(RPL_QUIT(_nickName, msg), getSocket());
        it->second->suppressUserFromChannel(_socket, _socket);
    }

	return (retVal);
}

void Client::partChannel(std::string &channel, std::string msg) {
    std::map<std::string, Channel *>::iterator it = _channels.find(channel);

    if (it == _channels.end()) {
        return ;
    }
	it->second->sendMsgToAllChannelMember(RPL_PART(_nickName, it->second->getChannelName().asString(), msg), getSocket());
    it->second->suppressUserFromChannel(_socket, _socket );
    sendToFd( _socket, RPL_PART( _nickName, it->second->getChannelName().asString(), msg ) );
    _channels.erase(channel);
}

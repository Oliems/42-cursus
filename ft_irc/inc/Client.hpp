#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "def.hpp"
#include "Channel.hpp"
#include <vector>
#include <string>
#include <map>
#include <deque>

class Channel;

class Client {
public:
    Client();
    Client( int fd );
    ~Client() {};

    void addChannel( std::string channelName, Channel * channel );
    void removeChannel( std::string channel );

    bool isRegistered( void );

    void setNickName( std::string nickName );
    void setHostName( std::string hostName );
    void setUserName( std::string userName );
    void setRealName( std::string realName );
    void setModerate( int num );

    int getModerate( void ) const;
    tSocket getSocket( void ) const;
    std::string const & getNickName( void ) const;
    std::string const & getHostName( void ) const;
    std::string const & getUserName( void ) const;
    std::string const & getRealName( void ) const;
    int getNbChannels( void ) const;
    std::map<std::string, Channel *> & getChannels( void );
	std::vector<std::string> getOutOfServer(  std::string &msg);

    void partChannel(std::string & channel,  std::string msg);


private:
    tSocket _socket;
    std::string _nickName;
    std::string _hostName;
    std::string _userName;
    std::string _realName;
    int _moderate;
    std::map<std::string, Channel *> _channels; /* Channels the user has joined */
};

#endif

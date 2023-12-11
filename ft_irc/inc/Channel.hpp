#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "ChannelName.hpp"
#include "Client.hpp"
#include "def.hpp"
#include <deque>
#include <iomanip>
#include <map>
#include <ostream>
#include <string>
#include <vector>

typedef unsigned int tModeMask;

enum eModeMasks {
    DEFAULT = 0b000000000,
    INVITE_ONLY = 0b000000001,
    TOPIC_FR_OP = 0b000000010,
    PASS_NEEDED = 0b000000100,
    LIMIT_USERS = 0b000001000
};

typedef struct sClientsRights {
    bool isOperator;
    Client * client;
    int insult;
} tClientRights;

#define MAX_LIMIT 60

class Channel {

private:
    std::map<tSocket, tClientRights> _clients;
    std::string _passWord;
    ChannelName _channelName;
    std::string _topic;
    int _nbOperator;
    tModeMask _mode;
    unsigned int _userLimit;
    std::map<tSocket, std::string> _invited;
    void setPassword( std::string pass );
    Channel();

    void modeUp( tSocket setter, tModeStruct modeInstruction, bool & change );
    void modeDown( tSocket setter, tModeStruct modeInstruction, bool & change );

public:
    Channel( ChannelName channelName, std::string pass );
    ~Channel();

    int getNbUser() const;
    tClientRights getClientRights( tSocket socket ) const;
    std::string getPassWord( void ) const;
    ChannelName getChannelName( void ) const;
    std::string getTopic( void ) const;

    void partChannel( Client client,  std::string reasonMsg );

    //void changePassWord( std::string pass, tSocket client );

    void addUserToChannel( tClientRights & clientRight, std::string password );

    bool kickUserFromChannel( Client * target, tSocket client );

    int incrementInsult( tSocket socket );

    void topicCmd( tSocket setter, std::string topic,  std::string const & nick );
    void topicCmd( tSocket setter,  std::string nick );

    void modeCmd( tSocket setter, tModeStruct modeInstruction,  bool setting );
    std::string listRights( void ) const;
    std::string listClients( void ) const;

    void suppressUserFromChannel( tSocket sender, tSocket target);

    bool isOnChannel(  Client client );
    void sendMsgToAllChannelMember(  std::string msg, tSocket sender );
    void sendMsgToAllByNick(  std::string first, std::string second ) const;

    bool inviteUserToChannel( tSocket sender, tSocket target, std::string nick );
};

#endif

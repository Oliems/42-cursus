#ifndef SERVER_HPP
# define SERVER_HPP

# include "Channel.hpp"
# include "Client.hpp"
# include "def.hpp"
# include "macro.hpp"
# include "utils.hpp"
# include <deque>
# include <iostream>
# include <map>
# include <sstream>
# include <string>

extern bool gQuit;

struct sMessage {
    tSocket fd;
    std::string msg;
};

class Channel;
class Server;
typedef enum eResponse {
	NONE,
	NEED_MORE_PARAMS,
	NO_SUCH_NICK
} tResponse;

class NetworkManager;

typedef void ( Server::*cmdHandler )( tSocket, std::string, Client * client);
typedef tResponse ( Server::*parsingModeFn )( std::vector<std::string> & parsedMessage, tModeStruct & toFill );

class Server {
public:
    Server( char * port, char * password, NetworkManager & netm);
    ~Server();
	void processMessage(tMessage &message);
	void closeConnection(tSocket fd, std::string & reason);

private:
	NetworkManager &_ntm;

    std::map<std::string, Client *> _nickMap;
    std::map<tSocket const, Client> _clients;
    std::map<std::string, Channel> _channelMap;

    std::string _passWord;
    std::vector<std::string> _fortunes;
    std::vector<std::string> _jokes;
    std::vector<std::string> _insult;
    std::map<std::string, cmdHandler> _cmdHandlers;
    std::map<char, parsingModeFn> _parsingModeMap;

    void userMessage( tSocket socket, std::string cmd, Client * client);
    void passMessage( tSocket socket, std::string cmd, Client * client);
    void nickMessage( tSocket socket, std::string cmd, Client * client);
    void kickMessage( tSocket socket, std::string cmd, Client * client);
    void inviteMessage( tSocket socket, std::string cmd, Client * client);
    void topicMessage( tSocket socket, std::string cmd, Client * client);
    void modeMessage( tSocket socket, std::string cmd, Client * client);
    void privmsgMessage( tSocket socket, std::string cmd, Client * client);
    void pingMessage( tSocket socket, std::string cmd, Client * client);
    void joinMessage( tSocket socket, std::string cmd, Client * client);
    void partMessage( tSocket socket, std::string cmd, Client * client);
    void quitMessage( tSocket socket, std::string cmd, Client * client);
    void welcomeMessage( tSocket socket, std::string cmd);
    void botHandle( tSocket const socket, std::vector<std::string> parsedCmd );
    void setupBot();
	void deleteChannelFromMapIfEmpty( std::map<std::string, Channel>::iterator channelMapIt );
    std::string moderate( tSocket socket, std::vector<std::string> parsedCmd);

    bool fillTModeStruct( std::vector<std::string> & parsedMessage, tModeStruct & toFill, const tSocket socket, Channel &channel );
	tResponse kset( std::vector<std::string> & parsedMessage, tModeStruct & toFill );
	tResponse tset( std::vector<std::string> & parsedMessage, tModeStruct & toFill );
	tResponse iset( std::vector<std::string> & parsedMessage, tModeStruct & toFill );
	tResponse lset( std::vector<std::string> & parsedMessage, tModeStruct & toFill );
	tResponse oset( std::vector<std::string> & parsedMessage, tModeStruct & toFill );


};

#endif

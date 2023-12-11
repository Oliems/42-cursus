#include "Server.hpp"
#include "macro.hpp"
#include "utils.hpp"
#include <fstream> /* std::ifstream */

using std::string;

Server::Server( char * port, char * password, NetworkManager &ntm)
    : _ntm(ntm), _passWord( password ) {
		(void)port;
    this->_cmdHandlers[ "USER" ] = &Server::userMessage;
    this->_cmdHandlers[ "PASS" ] = &Server::passMessage;
    this->_cmdHandlers[ "NICK" ] = &Server::nickMessage;
    this->_cmdHandlers[ "KICK" ] = &Server::kickMessage;
    this->_cmdHandlers[ "INVITE" ] = &Server::inviteMessage;
    this->_cmdHandlers[ "TOPIC" ] = &Server::topicMessage;
    this->_cmdHandlers[ "MODE" ] = &Server::modeMessage;
    this->_cmdHandlers[ "PRIVMSG" ] = &Server::privmsgMessage;
    this->_cmdHandlers[ "PING" ] = &Server::pingMessage;
    this->_cmdHandlers[ "JOIN" ] = &Server::joinMessage;
    this->_cmdHandlers[ "PART" ] = &Server::partMessage;
    this->_cmdHandlers[ "QUIT" ] = &Server::quitMessage;
    this->_parsingModeMap[ 'i' ] = &Server::iset;
    this->_parsingModeMap[ 't' ] = &Server::tset;
    this->_parsingModeMap[ 'k' ] = &Server::kset;
    this->_parsingModeMap[ 'o' ] = &Server::oset;
    this->_parsingModeMap[ 'l' ] = &Server::lset;
    setupBot();
}

Server::~Server() {
}

void Server::setupBot() {
    string fortuneFile = "src/InputFiles/Fortunes.txt";
	string jokesFile = "src/InputFiles/Jokes.txt";
	string insultFile = "src/InputFiles/Insult.txt";

    std::ifstream fortunesStream( fortuneFile.c_str() ), jokesStream( jokesFile.c_str() ), insultStream( insultFile.c_str() );
    if ( !fortunesStream.is_open() ) {
        throw std::ios_base::failure( fortuneFile + ": couldn't open file" );
    }
    if ( !jokesStream.is_open() ) {
        throw std::ios_base::failure( jokesFile + ": couldn't open file" );
    }
    if ( !insultStream.is_open() ) {
        throw std::ios_base::failure( insultFile + ": couldn't open file" );
    }
    std::string buffer, fortunes = "";
    while ( std::getline( fortunesStream, buffer ) ) {
        if ( buffer != "%" )
            fortunes += buffer;
        else {
            _fortunes.push_back( fortunes );
            fortunes = "";
        }
    }
    while ( std::getline( jokesStream, buffer ) ) {
        _jokes.push_back( buffer );
    }
    while ( std::getline( insultStream, buffer ) ) {
        _insult.push_back( buffer );
    }
}



static string extractCommand(string &line) {
	std::size_t spaceIdx = line.find(' ');
	if (spaceIdx == line.npos)
		return (line);
	return (line.substr(0, spaceIdx));
}

void Server::processMessage(tMessage & message) {

	if (message.msg.empty()) {
		return ;
	}

	std::cout << "irc: from " << message.fd << ": " << message.msg << std::endl;

	std::string command = extractCommand(message.msg);

	std::map<std::string, cmdHandler>::iterator handler = _cmdHandlers.find(command);
	if (handler == _cmdHandlers.end()) {
		sendToFd(message.fd, ERR_UNKNOWNCOMMAND( command ));
		return ;
	}

	std::map<tSocket, Client>::iterator clientIt = _clients.find(message.fd);
	if (clientIt == _clients.end()) {
		if (command == "PASS")
			passMessage(message.fd, message.msg, NULL);
        if (command == "QUIT")
            quitMessage(message.fd, message.msg, NULL);
		return ;
	}

	Client client = clientIt->second;

	if (client.isRegistered() == false && command != "NICK" && command != "USER" && command != "QUIT" ) {
		sendToFd( message.fd, ERR_NOTREGISTERED);
		return ;
	}

	( this->*( handler->second ) )( message.fd, message.msg, &clientIt->second);
}
#include "Server.hpp"
#include <ctime> /* time(), localtime() */

static std::string getCurrentDateTime() {
    time_t now = time( 0 );
    char buf[ 80 ];

    strftime( buf, sizeof( buf ), "%Y-%m-%d %X", localtime( &now ) );
    return buf;
}

/* The server sends Replies 001 to 004 to a user upon successful registration. */
void Server::welcomeMessage( tSocket socket, std::string cmd ) {
    ( void )cmd;
    Client & client = this->_clients.find( socket )->second;
    std::string nick = client.getNickName();
    if ( client.getNickName().empty() == false ) {
        /* Only send the welcome message if the user has successfully enterered a nickname */
        sendToFd( socket, RPL_WELCOME( nick, client.getUserName(), client.getHostName() ) );
        sendToFd( socket, RPL_YOURHOST( nick ) );
        sendToFd( socket, RPL_CREATED( nick, getCurrentDateTime() ) );
        sendToFd( socket, RPL_MYINFO( nick ) );
        sendToFd( socket, ":Hal PRIVMSG " + nick + " :Hey I'm Hal, your bot on this server." );
        sendToFd( socket, ":Hal PRIVMSG " + nick + " :You can ask me for a JOKE or a FORTUNE, I've got plenty of them!" );
        sendToFd( socket, ":Hal PRIVMSG " + nick + " :Please be respectful on every channel you talk on. Be aware that I'll moderate your chat and kick you if I have to.\n" );
        sendToFd( socket, ":Hal PRIVMSG " + nick + " :Have a good day! :D" );
        sendToFd( socket, ":Hal PRIVMSG " + nick + " :Hal" );
    }
}

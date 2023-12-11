#ifndef MACRO_HPP
#define MACRO_HPP

#include "def.hpp"

#define NUMRPL( num ) ( std::string( ":" ) + SERVER_NAME + " " + num + " " )

/* 401 */
#define ERR_NOSUCHNICK( sender, target ) ( NUMRPL( "401" ) + sender + " " + target + " :No such nick/channel" )
/* 402 */
#define ERR_NOSUCHSERVER( server ) ( NUMRPL( "402" ) + server + " :No such server" )
/* 403 */
#define ERR_NOSUCHCHANNEL( channel ) ( NUMRPL( "403" ) + channel + " :No such channel" )
/* 405 */
#define ERR_TOOMANYCHANNELS( client, channelName ) ( NUMRPL( "405" ) + client + " " + channelName + " :You have joined too many channels" )
/* 412 */
#define ERR_NOTEXTTOSEND( client ) ( NUMRPL( "412" ) + client + " :No text to send" )
/* 421 */
#define ERR_UNKNOWNCOMMAND( command ) ( NUMRPL( "421" ) + command + " :Unknown command" )
/* 431 */
#define ERR_NONICKNAMEGIVEN( client ) ( NUMRPL( "431" ) + client + " :No nickname given" )
/* 432 */
#define ERR_ERRONEUSNICKNAME( nick ) ( NUMRPL( "432" ) + nick + " :Erroneus nickname" )
/* 433 */
#define ERR_NICKNAMEINUSE( nick ) ( NUMRPL( "433" ) + nick + " :Nickname is already in use" )
/* 441 */
#define ERR_USERNOTINCHANNEL( nick, channelName ) ( NUMRPL( "441" ) + nick + " " + channelName + " :They aren't on that channel" )
/* 442 */
#define ERR_NOTONCHANNEL( nick, channelName ) ( NUMRPL( "442" ) + nick + " " + channelName + " :You're not on that channel" )
/* 451 */
#define ERR_NOTREGISTERED ( NUMRPL( "451" ) + "Client" + " :You have not registered" )
/* 461 */
#define ERR_NEEDMOREPARAMS( nick, command ) ( NUMRPL( "461" ) + nick + " " + command + " :Not enough parameters" )
#define ERR_NEEDMOREPARAMS_CHAN( nick, command, channelName ) ( NUMRPL( "461" ) + command + " " + channelName + " :Not enough parameters" )
#define ERR_NOSUCHNICK_CHAN( sender, command, target, channelName ) ( NUMRPL( "401" ) + command + " " + channelName + " :" + target + " No such nick/channel" )
/* 462 */
#define ERR_ALREADYREGISTERED( nick ) ( NUMRPL( "462" ) + nick + " :Unauthorized command (already registered)" )
/* 464 */
/* This message is sent directly so we need the \r\n here */
#define ERR_PASSWDMISMATCH ( NUMRPL( "464" ) + "Client" + " :Password incorrect\r\n" )
/* 467 */
#define ERR_KEYSET( channel ) ( NUMRPL( "467" ) + channel + " :Channel key already set" )
/* 471 */
#define ERR_CHANNELISFULL( nick, channelName ) ( NUMRPL( "471" ) + nick + " " + channelName + " :Cannot join channel (+l)" )
/* 473 */
#define ERR_INVITEONLYCHAN( channelName ) ( NUMRPL( "473" ) + channelName + " :Cannot join channel (+i)" )
/* 475 */
#define ERR_BADCHANNELKEY( nick, channelName ) ( NUMRPL( "475" ) + nick + " " + channelName + " :Cannot join channel (+k)" )
/* 482 */
#define ERR_CHANOPRIVSNEEDED( nick, channelName ) ( NUMRPL( "482" ) + nick + " " + channelName + " :You are not channel operator" )
/* 501 */
#define ERR_UMODEUNKOWNFLAG( channelName, nick, option ) ( NUMRPL( "501" ) + nick + " " + channelName + " :" + option + " is not a managed option" )

/* RPL*/
/* 001 */
#define RPL_WELCOME( nick, user, host ) ( NUMRPL( "001" ) + nick + " :Welcome to the " + SERVER_NAME + " Network, " + nick + "!" + user + "@" + host )
/* 002 */
#define RPL_YOURHOST( nick ) ( NUMRPL( "002" ) + nick + " :Your host is " + SERVER_NAME + ", running version " + VERSION )
/* 003 */
#define RPL_CREATED( nick, creationDate ) ( NUMRPL( "003" ) + nick + " :This server was created " + creationDate )
/* 004 */
#define RPL_MYINFO( nick ) ( NUMRPL( "004" ) + nick + " " + SERVER_NAME + " " + VERSION + " " + CHANMODE )
/* 324 */
#define RPL_CHANNELMODEIS( nick, channelName, rights ) ( NUMRPL( "324" ) + nick + " " + channelName + " " + rights )
/* 331 */
#define RPL_NOTOPIC( channelName ) ( NUMRPL( "331" ) + channelName + " :No topic is set" )
/* 332 */
#define RPL_TOPIC( nick, channelName, topic ) ( NUMRPL( "332" ) + nick + " " + channelName + " :" + topic )
/* 341 */
#define RPL_INVITING( channel, sender, target ) ( NUMRPL( "341" ) + sender + " " + target + " " + channel )
/* 353 */
#define RPL_NAMREPLY( nick, channelName, listClients ) ( NUMRPL( "353" ) + nick + " = " + channelName + " :" + listClients )
/*Our own*/
#define RPL_JOIN( nick, channelName ) ":" + nick + " JOIN " + channelName
/*Our own*/
#define RPL_PART( nick, channelName, reasonMsg ) ":" + nick + " PART " + channelName + " " + reasonMsg
/*Our own*/
#define RPL_KICK( msgReason ) ( "KICK" + msgReason )
/*Our own*/
#define RPL_QUIT( client, reason ) ":" + client + " QUIT" + reason
/*Our own*/
#define RPL_NICK_CHANGE( oldnick, newnick, username, hostname ) ( std::string( ":" ) + oldnick + "!" + username + "@" + hostname + " NICK " + newnick )
/*Our own*/
#define RPL_NICK_REGISTER( nick ) ( std::string( "NICK " ) + nick )

/* RPL Bot */
/*Our own*/
#define RPL_HAL_WARNING( target, nbWarning ) ":Hal PRIVMSG " + target + " :Watch your language or I'll kick you out of " + target + ". Warning : " + static_cast<char>( nbWarning + 48 ) + "/3"
/*Our own*/
#define RPL_HAL_BOTHANDLE( msg ) ":Hal PRIVMSG :Hal :" + msg
/*Our own*/
#define RPL_HAL_NOFOUND ":Hal PRIVMSG Hal :I don't understand this command. Use JOKES / FORTUNES to communicate with me."
/*Our own*/
#define RPL_HAL_KICK( target, client ) ":Hal KICK " + target + " " + client + " Hal kicked out " + client + " because he was insulting!"
/*Our own*/
#define RPL_HAL_KICKED_YOU( target, client ) ":Hal KICK " + target + " " + client + " kicked you out because you were insulting."

#endif

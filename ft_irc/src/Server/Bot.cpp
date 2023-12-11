#include "Server.hpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>

using std::string;
using std::vector;

void Server::botHandle( tSocket const socket,  vector<string> parsedCmd ){
    std::for_each(parsedCmd[ 2 ].begin(), parsedCmd[ 2 ].end(), toupper);

    if (parsedCmd[ 2 ].find("FORTUNES") != string::npos ){
        int randomNum = std::rand() % (_fortunes.size() + 1);
        sendToFd(socket, RPL_HAL_BOTHANDLE(_fortunes[randomNum]));
		return ;
    }
    
	if (parsedCmd[ 2 ].find("JOKES") != string::npos ){
        int randomNum = std::rand() % (_jokes.size() + 1);
        sendToFd(socket, RPL_HAL_BOTHANDLE(_jokes[randomNum]));
		return ;
    }

	sendToFd(socket, RPL_HAL_NOFOUND);
}

string Server::moderate( tSocket socket, vector<string> parsedCmd) {
    string cmd;
    string msg = "";
    bool insult = false;
    for ( size_t i = 2; i < parsedCmd.size(); i++ ) {
        vector<string>::iterator it;
        if ( i == 2 )
            parsedCmd[ i ].erase( std::remove( parsedCmd[ i ].begin(), parsedCmd[ i ].end(), ':' ), parsedCmd[ i ].end() );
        it = find( _insult.begin(), _insult.end(), parsedCmd[ i ] );
        if ( it != _insult.end() ) {
            replaceChar( parsedCmd[ i ] );
            insult = true;
        }
        msg += parsedCmd[ i ] + " ";
    }
    if ( insult ) {
        int nbWarning = _channelMap.find( parsedCmd[ 1 ] )->second.incrementInsult( socket );
        sendToFd( socket, RPL_HAL_WARNING( parsedCmd[ 1 ], nbWarning ) );
    }
    cmd = parsedCmd[ 0 ] + " " + parsedCmd[ 1 ] + " " + msg;
    return ( cmd );
}

#include "utils.hpp"
#include "Server.hpp"
#include <algorithm>
#include <cstring>
#include <sys/socket.h>
#include <errno.h>

int isSpecial( int c ) {
    return ( c == '[' || c == ']' || c == '\\' || c == '`' || c == '_' || c == '^' || c == '{' || c == '|' || c == '}' );
}

/**
 * @brief Add a message to the queue of messages to be sent to clients.
 */
void sendToFd( tSocket dest, std::string msg ) {
	msg = msg + "\r\n";
	std::cout << "irc: to " << dest << ": " << msg;

	if (send(dest, msg.c_str(), msg.size(), 0) < 0
		&& errno != ECONNRESET && errno != EPIPE && errno != EBADF) {
		std::cerr << "Error : send() " << std::strerror(errno) << std::endl;
	}
}

std::vector<std::string> cmdSplit( std::string str, std::string seps ) {
    std::vector<std::string> parsedString;
    std::size_t prev = 0, pos;
    while ( ( pos = str.find_first_of( seps, prev ) ) != std::string::npos ) {
        if ( pos > prev )
            parsedString.push_back( str.substr( prev, pos - prev ) );
        prev = pos + 1;
    }
    if ( prev < str.length() )
        parsedString.push_back( str.substr( prev, std::string::npos ) );
    return parsedString;
}

void toUpper( char & c ) {
    c = std::toupper( static_cast<unsigned char>( c ) );
}

void replaceChar( std::string & str ) {
    int skip = 0;
    for ( size_t i = 1; i < str.size(); i++ ) {
        if ( str[ 0 ] == ':' )
            skip = 1;
        std::replace( str.begin() + 1, str.end(), str[ i + skip ], '*' );
    }
}

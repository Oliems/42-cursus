#ifndef UTILS_HPP
#define UTILS_HPP

#include "def.hpp"
#include <deque>
#include <string>
#include <vector>


std::vector<std::string> cmdSplit( std::string str, std::string seps );
void sendToFd( tSocket dest, std::string msg );
void toUpper( char & c );
void replaceChar( std::string & str );
int isSpecial( int c );

#endif

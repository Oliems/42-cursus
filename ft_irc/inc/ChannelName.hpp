#ifndef CHANNELNAME_HPP
#define CHANNELNAME_HPP

#include <string>

class ChannelName {

private:
    std::string _name;

public:
    ChannelName();
    ~ChannelName();

    ChannelName( std::string const & stringName );
    ChannelName( char const * cStrName );
    std::string getChannelName() const;
    void setChannelName( std::string );

    std::string asString() const;

    class BadChannelNameException : public std::exception {
        const char * what( void ) const throw();
    };

    class BadCharInChannelNameException : public std::exception {
        const char * what( void ) const throw();
    };

    class BadLengthException : public std::exception {
        const char * what( void ) const throw();
    };
};

#endif

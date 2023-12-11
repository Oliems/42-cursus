#include "ChannelName.hpp"

#include "utils.hpp"
#include <iostream>

ChannelName::ChannelName() {};

ChannelName::~ChannelName() {};

const char * ChannelName::BadLengthException::what( void ) const throw() {
    return ( "ChannelName length not in range [2-64]" );
}

const char * ChannelName::BadChannelNameException::what( void ) const throw() {
    return ( "ChannelName must start with # or &" );
}

const char * ChannelName::BadCharInChannelNameException::what( void ) const throw() {
    return ( "ChannelName contains invalid character(s)" );
}

ChannelName::ChannelName( const char * cStringName )
    : _name( std::string( cStringName ) ) {
    size_t len = _name.length();
    if ( len < 2 || len > 64 ) {
        throw( BadLengthException() );
    }
    if ( _name[ 0 ] != '#' && _name[ 0 ] != '&' ) {
        throw( BadChannelNameException() );
    }
    for ( size_t i = 1; cStringName[ i ] != '\0'; i++ ) {
        if ( !std::isalnum( cStringName[ i ] ) && !isSpecial( cStringName[ i ] ) ) {
            throw( BadCharInChannelNameException() );
        }
    }
}

ChannelName::ChannelName( const std::string & cStringName )
    : _name( cStringName ) {
    size_t len = _name.length();
    if ( len < 2 || len > 64 ) {
        throw( BadLengthException() );
    }
    if ( _name[ 0 ] != '#' && _name[ 0 ] != '&' ) {
        throw( BadChannelNameException() );
    }
    for ( size_t i = 1; cStringName[ i ] != '\0'; i++ ) {
        if ( !std::isalnum( cStringName[ i ] ) && !isSpecial( cStringName[ i ] ) ) {
            throw( BadCharInChannelNameException() );
        }
    }
}

std::string ChannelName::asString() const {
    return ( _name );
}

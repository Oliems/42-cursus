/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:23:24 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/28 14:54:30 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
    this->_arrayFunc[ 0 ] = &Harl::_debug;
    this->_arrayFunc[ 1 ] = &Harl::_info;
    this->_arrayFunc[ 2 ] = &Harl::_warning;
    this->_arrayFunc[ 3 ] = &Harl::_error;
}
Harl::~Harl() { }

int hash( std::string s ) {
    unsigned long hash = 5381;

    for ( size_t i = 0; i < s.length(); i++ )
        hash = ( ( hash << 5 ) + hash ) + s[ i ];
    switch ( hash ) {
    case DEBUG_HASH:
        return 0;
    case INFO_HASH:
        return 1;
    case WARNING_HASH:
        return 2;
    case ERROR_HASH:
        return 3;
    default:
        return -1;
    }
}

void Harl::complain( std::string level ) {
    int l = hash( level );
    if ( l >= 0 )
        for ( ; l < 4; l++ )
            ( this->*( _arrayFunc[ l ] ) )();
    else
        std::cout << "Unknown comment level.\n";
}

void Harl::_debug( void ) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !\n";
}
void Harl::_info( void ) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more!\n";
}
void Harl::_warning( void ) {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}
void Harl::_error( void ) {
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

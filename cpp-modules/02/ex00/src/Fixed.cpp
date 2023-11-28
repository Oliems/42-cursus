/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:52:51 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/20 18:35:05 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
    : _value( 0 ) {
    std::cout << "Default constructor used.\n";
}

Fixed::Fixed( const Fixed & src )
    : _value( src._value ) {
    std::cout << "Copy constructor used.\n";
}

Fixed::~Fixed() {
    std::cout << "Destructor used.\n";
}

Fixed & Fixed::operator=( Fixed const & src ) {
    std::cout << "Copy assignement operator used.\n";
    this->_value = src.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function used.\n";
    return this->_value;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function used.\n";
    this->_value = raw;
}

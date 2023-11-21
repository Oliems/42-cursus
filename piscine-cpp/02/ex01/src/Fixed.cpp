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
#include <cmath>
#include <iostream>

Fixed::Fixed()
    : _value( 0 ) {
    std::cout << "Default constructor used.\n";
}

Fixed::Fixed( const Fixed & src )
    : _value( src._value ) {
    std::cout << "Copy constructor used.\n";
}

Fixed::Fixed( int const n ) {
    std::cout << "Int constructor used.\n";
    this->_value = n << this->_fractional;
}

Fixed::Fixed( float const n ) {
    std::cout << "Float constructor used.\n";
    this->_value = roundf( n * ( 1 << this->_fractional ) );
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
    return this->_value;
}

void Fixed::setRawBits( int const raw ) {
    this->_value = raw;
}

float Fixed::toFloat( void ) const {
    return ( float )this->_value / ( float )( 1 << this->_fractional );
}

int Fixed::toInt( void ) const {
    return roundf( this->_value / ( 1 << this->_fractional ) );
}

std::ostream & operator<<( std::ostream & o, Fixed const & f ) {
    o << f.toFloat();
    return o;
}

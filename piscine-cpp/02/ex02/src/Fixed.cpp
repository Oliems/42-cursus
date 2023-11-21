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
    // std::cout << "Default constructor used.\n";
}

Fixed::Fixed( const Fixed & src )
    : _value( src._value ) {
    // std::cout << "Copy constructor used.\n";
}

Fixed::Fixed( int const n ) {
    // std::cout << "Int constructor used.\n";
    this->_value = n << this->_fractional;
}

Fixed::Fixed( float const n ) {
    // std::cout << "Float constructor used.\n";
    this->_value = roundf( n * ( 1 << this->_fractional ) );
}

Fixed::~Fixed() {
    // std::cout << "Destructor used.\n";
}

Fixed & Fixed::operator=( Fixed const & src ) {
    // std::cout << "Copy assignement operator used.\n";
    this->_value = src.getRawBits();
    return *this;
}

bool Fixed::operator>( Fixed const & a ) const {
    return this->_value > a._value;
}

bool Fixed::operator<( Fixed const & a ) const {
    return this->_value < a._value;
}

bool Fixed::operator>=( Fixed const & a ) const {
    return this->_value >= a._value;
}

bool Fixed::operator<=( Fixed const & a ) const {
    return this->_value <= a._value;
}

bool Fixed::operator==( Fixed const & a ) const {
    return this->_value == a._value;
}

bool Fixed::operator!=( Fixed const & a ) const {
    return this->_value != a._value;
}

Fixed Fixed::operator+( Fixed const & a ) const {
    Fixed r;

    r.setRawBits( this->_value + a._value );
    return r;
}

Fixed Fixed::operator-( Fixed const & a ) const {
    Fixed r;

    r.setRawBits( this->_value - a._value );
    return r;
}

Fixed Fixed::operator*( Fixed const & a ) const {
    Fixed r;

    r.setRawBits( ( this->_value * a._value ) >> this->_fractional );
    return r;
}

Fixed Fixed::operator/( Fixed const & a ) const {
    Fixed r;

    r.setRawBits( ( this->_value << this->_fractional ) / a._value );
    return r;
}

Fixed & Fixed::operator++() {
    this->_value++;
    return *this;
}

Fixed & Fixed::operator--() {
    this->_value--;
    return *this;
}

Fixed Fixed::operator++( int ) {
    Fixed tmp( *this );

    this->_value++;
    return tmp;
}

Fixed Fixed::operator--( int ) {
    Fixed tmp( *this );

    this->_value--;
    return tmp;
}

Fixed & Fixed::min( Fixed & lhs, Fixed & rhs ) {
    return lhs < rhs ? lhs : rhs;
}

Fixed & Fixed::max( Fixed & lhs, Fixed & rhs ) {
    return lhs > rhs ? lhs : rhs;
}

Fixed const & Fixed::min( Fixed const & lhs, Fixed const & rhs ) {
    return lhs < rhs ? lhs : rhs;
}

Fixed const & Fixed::max( Fixed const & lhs, Fixed const & rhs ) {
    return lhs > rhs ? lhs : rhs;
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

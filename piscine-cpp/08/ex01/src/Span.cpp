/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:52:14 by mbarberi          #+#    #+#             */
/*   Updated: 2023/09/06 10:14:04 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdlib.h>
#include <vector>

Span::Span()
    : _n( 0 ) {
}

Span::Span( unsigned int n )
    : _n( n ) {
}

Span::Span( Span const & o ) {
    this->_n = o._n;
    this->_v = o._v;
}

Span::~Span() {
}

Span & Span::operator=( Span const & o ) {
    this->_n = o._n;
    this->_v = o._v;
    return *this;
}

void Span::addRange( unsigned int n ) {
    if ( n > this->_n - this->_v.size() )
        throw MaxSizeReachedException();
    std::vector<int> v( n );
    std::generate( v.begin(), v.end(), rand );
    this->_v.insert( this->_v.begin(), v.begin(), v.end() );
}

void Span::addNumber( int n ) {
    if ( this->_v.size() >= this->_n )
        throw MaxSizeReachedException();
    this->_v.push_back( n );
}

int Span::shortestSpan() {
    if ( this->_v.size() <= 1 )
        throw EmptySpanException();
    std::vector<int> tmp = this->_v;
    std::sort( tmp.begin(), tmp.end() );
    std::adjacent_difference( tmp.begin(), tmp.end(), tmp.begin() );
    return *std::min_element( tmp.begin(), tmp.end() );
}

int Span::longestSpan() {
    if ( this->_v.size() <= 1 )
        throw EmptySpanException();
    return *std::max_element( this->_v.begin(), this->_v.end() ) - *std::min_element( this->_v.begin(), this->_v.end() );
}

const char * Span::MaxSizeReachedException::what( void ) const throw() {
    return "Maximum size for Span reached.";
}

const char * Span::EmptySpanException::what( void ) const throw() {
    return "Span is empty.";
}

std::vector<int> const & Span::getVector( void ) const {
    return this->_v;
}

std::ostream & operator<<( std::ostream & o, const Span & span ) {
    std::vector<int> v = span.getVector();
    for ( std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++ )
        o << *it << " ";
    return o;
}

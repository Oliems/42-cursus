/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:08:54 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/02 09:24:34 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
    : _x( 0 )
    , _y( 0 ) {
}

Point::Point( float const x, float const y )
    : _x( x )
    , _y( y ) {
}

Point::Point( Point const & o )
    : _x( o._x )
    , _y( o._y ) {
}

Point::~Point() {
}

// const attributes must be initialized by the constructor and cannot be
// changed afterwards, therefore we can just return *this
Point & Point::operator=( Point const & o ) {
    ( void )o;
    return *this;
}

bool Point::operator==( Point const & o ) const {
    return ( ( this->getX() == o.getX() ) && ( this->getY() == o.getY() ) );
}

Fixed Point::getX() const {
    return this->_x;
}

Fixed Point::getY() const {
    return this->_y;
}

std::ostream & operator<<( std::ostream & o, Point const & p ) {
    o << "(" << p.getX().toFloat() << ", " << p.getY().toFloat() << ")";
    return o;
}

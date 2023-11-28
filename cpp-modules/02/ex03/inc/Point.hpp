/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:03:37 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/02 09:20:57 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
public:
    Point();
    Point( float const x, float const y );
    Point( Point const & o );
    ~Point();

    Point & operator=( Point const & o );
    bool operator==( Point const & o ) const;

    Fixed getX() const;
    Fixed getY() const;

private:
    Fixed const _x;
    Fixed const _y;
};

std::ostream & operator<<( std::ostream & o, Point const & p );

#endif

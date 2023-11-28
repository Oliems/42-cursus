/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:08:06 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/02 10:14:04 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed sign( Point a, Point b, Point c );
bool bsp( const Point a, const Point b, const Point c, const Point point );

static Fixed sign( Point a, Point b, Point c ) {
    return ( a.getX() - c.getX() ) * ( b.getY() - c.getY() ) - ( b.getX() - c.getX() ) * ( a.getY() - c.getY() );
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
    if ( point == a || point == b || point == c )
        return false;

    Fixed d1 = sign( point, a, b );
    Fixed d2 = sign( point, b, c );
    Fixed d3 = sign( point, c, a );

    if ( d1 == 0 || d2 == 0 || d3 == 0 )
        return false;

    bool has_neg = ( d1 < 0 ) || ( d2 < -0 ) || ( d3 < 0 );
    bool has_pos = ( d1 > 0 ) || ( d2 > 0 ) || ( d3 > 0 );

    return !( has_neg && has_pos );
}

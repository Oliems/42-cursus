/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:51:58 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/02 10:13:02 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( const Point a, const Point b, const Point c, const Point point );

int main( void ) {
    Point a( 0, 0 );
    Point b( 10, 0 );
    Point c( 0, 10 );
    Point p1( 0, 0 );
    Point p2( 10, 0 );
    Point p3( 0, 10 );
    Point p4( 3, 3 );
    Point p5( 3, 0.01 );
    Point p6( 1, 0 );
    Point p7( 5.5, 5.5 );

    std::cout << "A = " << a << "\n";
    std::cout << "B = " << b << "\n";
    std::cout << "C = " << c << "\n\n";

    std::cout << "P1 = " << p1 << "\n";
    std::cout << "P1 in triangle: " << ( bsp( a, b, c, p1 ) ? "true" : "false" ) << "\n\n";

    std::cout << "P2 = " << p2 << "\n";
    std::cout << "P2 in triangle: " << ( bsp( a, b, c, p2 ) ? "true" : "false" ) << "\n\n";

    std::cout << "P3 = " << p3 << "\n";
    std::cout << "P3 in triangle: " << ( bsp( a, b, c, p3 ) ? "true" : "false" ) << "\n\n";

    std::cout << "P4 = " << p4 << "\n";
    std::cout << "P4 in triangle: " << ( bsp( a, b, c, p4 ) ? "true" : "false" ) << "\n\n";

    std::cout << "P5 = " << p5 << "\n";
    std::cout << "P5 in triangle: " << ( bsp( a, b, c, p5 ) ? "true" : "false" ) << "\n\n";

    std::cout << "P6 = " << p6 << "\n";
    std::cout << "P6 in triangle: " << ( bsp( a, b, c, p6 ) ? "true" : "false" ) << "\n\n";

    std::cout << "P7 = " << p7 << "\n";
    std::cout << "P7 in triangle: " << ( bsp( a, b, c, p7 ) ? "true" : "false" ) << "\n\n";
    return 0;
}

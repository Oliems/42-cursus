/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:51:58 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 10:51:25 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "a = " << a << "\n";
    std::cout << "++a = " << ++a << "\n";
    std::cout << "a = " << a << "\n";
    std::cout << "a++ = " << a++ << "\n";
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "max(a, b) = " << Fixed::max( a, b ) << "\n";
    std::cout << "min(a, b) = " << Fixed::min( a, b ) << "\n";

    if ( b > 8 )
        std::cout << b << " is higher than 8\n";

    Fixed c;
    c++;
    --c;
    c++;
    ++c;
    if ( a != c )
        std::cout << a << " is not equal to " << c << "\n";
    return 0;
}

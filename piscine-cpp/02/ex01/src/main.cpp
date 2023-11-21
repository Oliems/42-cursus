/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:51:58 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 10:28:28 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << "\n";
    std::cout << "b is " << b << "\n";
    std::cout << "c is " << c << "\n";
    std::cout << "d is " << d << "\n";
    std::cout << "a is " << a.toInt() << " as integer\n";
    std::cout << "b is " << b.toInt() << " as integer\n";
    std::cout << "c is " << c.toInt() << " as integer\n";
    std::cout << "d is " << d.toInt() << " as integer\n";
    return 0;
}

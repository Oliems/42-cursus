/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:51:58 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/02 08:54:23 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    c = c;
    std::cout << a.getRawBits() << "\n";
    std::cout << b.getRawBits() << "\n";
    std::cout << c.getRawBits() << "\n";
    return 0;
}

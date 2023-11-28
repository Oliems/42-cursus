/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:54:29 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/30 11:23:17 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main( int argc, char ** argv ) {
    if ( argc != 2 )
        std::cout << "Usage: ./convert num\n";
    else
        ScalarConverter::convert( argv[ 1 ] );
    return 0;
}

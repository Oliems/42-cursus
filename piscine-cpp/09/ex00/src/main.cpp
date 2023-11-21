/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:52:47 by mbarberi          #+#    #+#             */
/*   Updated: 2023/09/16 17:11:34 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main( int argc, char ** argv ) {
    if ( argc != 2 ) {
        std::cerr << "Usage: ./btc input_file.txt\n";
        return 1;
    }
    ProcessInput( argv[ 1 ], "./input/data.csv" );
    return 0;
}

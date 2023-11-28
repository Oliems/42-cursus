/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:23:26 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/28 14:53:07 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main( int argc, char ** argv ) {
    Harl h;

    if ( argc != 2 ) {
        std::cout << "Usage: ./harlFilter <level>\n";
        return 0;
    }
    h.complain( argv[ 1 ] );
    return 0;
}

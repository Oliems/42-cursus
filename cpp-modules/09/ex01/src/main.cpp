/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:07:34 by mbarberi          #+#    #+#             */
/*   Updated: 2023/10/30 10:32:13 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main( int argc, char ** argv ) {
    if ( argc != 2 ) {
        std::cerr << "Usage: ./RPN 'expression'\n";
        return 1;
    }
    std::string exp( argv[ 1 ] );
    if ( exp.find_first_not_of( " \t\n\v\f\r" ) == std::string::npos ) {
        /* The string contains only whitespace */
        return 0;
    }
    try {
        int r = ResolveExpression( argv[ 1 ] );
        std::cout << r << '\n';
    } catch ( std::exception & e ) {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:52:04 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/26 11:20:39 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main( int argc, char ** argv ) {
    std::string s;
    if ( argc < 2 ) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

    } else {
        for ( int i = 1; i < argc; i++ )
            s += argv[ i ];
        for ( size_t i = 0; i < s.size(); i++ )
            s[ i ] = toupper( s[ i ] );
        std::cout << s;
    }
    std::cout << "\n";
    return 0;
}

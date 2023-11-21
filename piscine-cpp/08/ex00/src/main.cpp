/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:26:48 by mbarberi          #+#    #+#             */
/*   Updated: 2023/09/05 15:49:38 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main( void ) {
    std::list<int> l;
    std::vector<int> v;

    l.push_back( 1 ), l.push_back( 3 ), l.push_back( 5 ), l.push_back( 7 );
    v.push_back( 2 ), v.push_back( 4 ), v.push_back( 6 ), v.push_back( 8 );

    for ( int i = 0; i < 10; i++ ) {
        std::cout << "list: " << i << ": " << ( easyfind( l, i ) ? "not found." : "found." ) << "\n";
        std::cout << "vector: " << i << ": " << ( easyfind( v, i ) ? "not found." : "found." ) << "\n";
    }
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:45:14 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 13:45:32 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap a( "Jack" );
    ClapTrap x;
    ClapTrap y( a );

    std::cout << "\n"
              << a << "\n"
              << x << "\n"
              << y << "\n";
    x = a;
    std::cout << x << "\n\n";

    a.attack( "John" );
    a.attack( "John" );
    a.attack( "John" );
    a.attack( "John" );
    a.attack( "John" );
    a.takeDamage( 1 );
    a.beRepaired( 1 );
    a.attack( "John" );
    a.attack( "John" );
    a.attack( "John" );
    a.attack( "John" );
    a.attack( "John" );
    a.takeDamage( 15 );
    a.attack( "John" );
    return 0;
}

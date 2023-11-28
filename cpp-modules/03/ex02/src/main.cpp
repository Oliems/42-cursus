/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:45:14 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 15:03:00 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main( void ) {
    ClapTrap c;
    FragTrap f;
    FragTrap ft( "Jack" );
    FragTrap ftp( f );

    std::cout << "\n";
    std::cout << c << "\n";
    std::cout << f << "\n";
    std::cout << ft << "\n";
    std::cout << ftp << "\n\n";

    ft.attack( "John" );
    ft.takeDamage( 25 );
    ft.beRepaired( 10 );
    ft.highFivesGuys();
    std::cout << "\n"
              << ft << "\n\n";
    return 0;
}

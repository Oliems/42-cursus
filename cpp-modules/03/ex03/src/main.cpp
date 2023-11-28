/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:45:14 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 19:19:37 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main( void ) {
    DiamondTrap f;
    DiamondTrap ft( "Jack" );
    DiamondTrap ftp( f );

    std::cout << "\n";
    std::cout << f << "\n";
    std::cout << ft << "\n";
    ft = f;
    std::cout << ft << "\n";
    std::cout << ftp << "\n\n";

    ft.attack( "John" );
    ft.takeDamage( 25 );
    ft.beRepaired( 10 );
    ft.highFivesGuys();
    ft.guardGate();
    f.whoAmI();
    ft.whoAmI();
    ftp.whoAmI();
    std::cout << "\n"
              << ft << "\n\n";
    return 0;
}

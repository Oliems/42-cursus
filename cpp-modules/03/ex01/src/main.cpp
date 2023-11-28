/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:45:14 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 14:54:49 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main( void ) {
    ClapTrap c;
    ScavTrap s;
    ScavTrap st( "Jack" );
    ScavTrap stp( s );

    std::cout << "\n";
    std::cout << c << "\n";
    std::cout << s << "\n";
    std::cout << st << "\n";
    std::cout << stp << "\n\n";

    st.attack( "John" );
    st.takeDamage( 25 );
    st.beRepaired( 10 );
    st.guardGate();
    st.guardGate();
    std::cout << "\n"
              << st << "\n\n";
    return 0;
}

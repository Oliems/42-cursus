/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:26:51 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/28 10:26:30 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
    {
        Weapon club = Weapon( "crude spiked club" );
        HumanA bob( "Bob", club );
        bob.attack();
        club.setType( "some other type of club" );
        bob.attack();
    }
    {
        Weapon club = Weapon( "crude spiked club" );
        HumanB jim( "Jim" );
        jim.attack();
        jim.setWeapon( club );
        club.setType( "some other type of club" );
        jim.attack();
    }
    return 0;
}

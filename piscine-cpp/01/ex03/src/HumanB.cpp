/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:26:49 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/28 10:29:38 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB( std::string name )
    : _name( name )
    , _weapon( NULL ) {
}
HumanB::~HumanB() { }

const std::string & HumanB::getName() const {
    return this->_name;
}

void HumanB::attack() {
    if ( this->_weapon )
        std::cout << this->getName() << " attack with their " << this->_weapon->getType() << "\n";
    else
        std::cout << this->getName() << " attack with their "
                  << "bare hands\n";
}

void HumanB::setWeapon( Weapon & weapon ) {
    this->_weapon = &weapon;
}

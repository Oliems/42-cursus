/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:26:47 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/28 10:29:03 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA( std::string name, Weapon & weapon )
    : _name( name )
    , _weapon( weapon ) {
}

HumanA::~HumanA() { }

const std::string & HumanA::getName() const {
    return this->_name;
}

void HumanA::attack() {
    std::cout << this->getName() << " attack with their " << this->_weapon.getType() << "\n";
}

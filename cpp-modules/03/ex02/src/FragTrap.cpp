/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:56:11 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 16:07:00 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap: default constructor used.\n";
    this->_hp = 100;
    this->_ep = 100;
    this->_ad = 30;
}

FragTrap::FragTrap( std::string const & name )
    : ClapTrap( name ) {
    std::cout << "FragTrap: constructor with `name' parameter used.\n";
    this->_hp = 100;
    this->_ep = 100;
    this->_ad = 30;
}

FragTrap::FragTrap( FragTrap const & o )
    : ClapTrap( o ) {
    std::cout << "FragTrap: copy constructor used.\n";
    this->_hp = o._hp;
    this->_ep = o._ep;
    this->_ad = o._ad;
    this->_name = o._name;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap: destructor used.\n";
}

FragTrap & FragTrap::operator=( FragTrap const & o ) {
    std::cout << "FragTrap: assignement operator used.\n";
    this->_hp = o._hp;
    this->_ep = o._ep;
    this->_ad = o._ad;
    this->_name = o._name;
    return *this;
}

void FragTrap::highFivesGuys( void ) {
    std::cout << "FragTrap " << this->_name << " asks for a high five.\n";
}

std::ostream & operator<<( std::ostream & o, FragTrap const & c ) {
    o << "FragTrap: " << c.getName() << " | HP: " << c.getHp() << ", EP: " << c.getEp() << ", AD: " << c.getAd();
    return o;
}

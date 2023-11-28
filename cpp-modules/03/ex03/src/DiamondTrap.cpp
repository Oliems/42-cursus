/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:23:41 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 19:25:09 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    std::cout << "DiamondTrap: default constructor used.\n";
    this->_hp = this->FragTrap::_hp;
    this->_ep = this->ScavTrap::_ep;
    this->_ad = this->FragTrap::_ad;
    this->_name = "Default";
}

DiamondTrap::DiamondTrap( std::string const & name )
    : ClapTrap( name + "_clap_name" )
    , ScavTrap( name + "_clap_name" )
    , FragTrap( name + "_clap_name" ) {
    std::cout << "DiamondTrap: constructor with `name' parameter used.\n";
    this->_hp = this->FragTrap::_hp;
    this->_ep = this->ScavTrap::_ep;
    this->_ad = this->FragTrap::_ad;
    this->_name = name;
}

DiamondTrap::DiamondTrap( DiamondTrap const & o )
    : ClapTrap( o._name + "_clap_name" )
    , ScavTrap( o._name + "_clap_name" )
    , FragTrap( o._name + "_clap_name" ) {
    std::cout << "DiamondTrap: copy constructor used.\n";
    this->_hp = o.getHp();
    this->_ep = o.getEp();
    this->_ad = o.getAd();
    this->_name = o.getName();
    this->_guarding = o.getGuarding();
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap: destructor used.\n";
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & o ) {
    std::cout << "DiamondTrap: assignement operator used.\n";
    this->_hp = o.getHp();
    this->_ep = o.getEp();
    this->_ad = o.getAd();
    this->_name = o.getName();
    this->_guarding = o.getGuarding();
    return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << "My name is " << this->_name << " and my Clap name is " << this->ClapTrap::_name << ".\n";
}

std::ostream & operator<<( std::ostream & o, DiamondTrap const & c ) {
    o << "DiamondTrap: " << c.getName() << " | HP: " << c.getHp() << ", EP: " << c.getEp() << ", AD: " << c.getAd() << ", GKM: " << ( c.getGuarding() ? "on" : "off" );
    return o;
}

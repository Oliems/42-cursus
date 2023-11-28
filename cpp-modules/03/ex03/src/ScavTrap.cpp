/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:56:11 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 16:07:00 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap: default constructor used.\n";
    this->_hp = 100;
    this->_ep = 50;
    this->_ad = 20;
    this->_guarding = false;
}

ScavTrap::ScavTrap( std::string const & name )
    : ClapTrap( name ) {
    std::cout << "ScavTrap: constructor with `name' parameter used.\n";
    this->_hp = 100;
    this->_ep = 50;
    this->_ad = 20;
    this->_guarding = false;
}

ScavTrap::ScavTrap( ScavTrap const & o )
    : ClapTrap( o ) {
    std::cout << "ScavTrap: copy constructor used.\n";
    this->_hp = o._hp;
    this->_ep = o._ep;
    this->_ad = o._ad;
    this->_name = o._name;
    this->_guarding = o._guarding;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap: destructor used.\n";
}

ScavTrap & ScavTrap::operator=( ScavTrap const & o ) {
    std::cout << "ScavTrap: assignement operator used.\n";
    this->_hp = o._hp;
    this->_ep = o._ep;
    this->_ad = o._ad;
    this->_name = o._name;
    this->_guarding = o._guarding;
    return *this;
}

void ScavTrap::attack( const std::string & target ) {
    if ( this->_hp <= 0 ) {
        std::cout << "ScavTrap " << this->_name << " is dead!\n";
        return;
    }
    if ( this->_ep > 0 )
        std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_ad << " points of damage!\n";
    else
        std::cout << "Not enough EP left to perform this action.\n";
    this->_ep--;
}

bool ScavTrap::getGuarding() const {
    return this->_guarding;
}

void ScavTrap::guardGate() {
    if ( this->_guarding )
        std::cout << this->_name << " is already in Gate Keeper Mode.\n";
    else
        std::cout << this->_name << " is now in Gate Keeper Mode.\n";
    this->_guarding = true;
}

std::ostream & operator<<( std::ostream & o, ScavTrap const & c ) {
    o << "ScavTrap: " << c.getName() << " | HP: " << c.getHp() << ", EP: " << c.getEp() << ", AD: " << c.getAd() << ", GKM: " << ( c.getGuarding() ? "on" : "off" );
    return o;
}

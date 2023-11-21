/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:45:12 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 16:07:00 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
    : _hp( 10 )
    , _ep( 10 )
    , _ad( 0 )
    , _name( "Default" ) {
    std::cout << "ClapTrap: default constructor used.\n";
}

ClapTrap::ClapTrap( std::string const & name )
    : _hp( 10 )
    , _ep( 10 )
    , _ad( 0 )
    , _name( name ) {
    std::cout << "ClapTrap: constructor with `name' parameter used.\n";
}

ClapTrap::ClapTrap( ClapTrap const & o )
    : _hp( o._hp )
    , _ep( o._ep )
    , _ad( o._ad )
    , _name( o._name ) {
    std::cout << "ClapTrap: copy constructor used.\n";
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap: destructor used.\n";
}

ClapTrap & ClapTrap::operator=( ClapTrap const & o ) {
    std::cout << "ClapTrap: assignement operator used.\n";
    this->_name = o._name;
    this->_hp = o._hp;
    this->_ep = o._ep;
    this->_ad = o._ad;
    return *this;
}

int ClapTrap::getHp() const {
    return this->_hp;
}

int ClapTrap::getEp() const {
    return this->_ep;
}

int ClapTrap::getAd() const {
    return this->_ad;
}

std::string ClapTrap::getName() const {
    return this->_name;
}

void ClapTrap::attack( const std::string & target ) {
    if ( this->_hp <= 0 ) {
        std::cout << "ClapTrap " << this->_name << " is dead!\n";
        return;
    }
    if ( this->_ep > 0 )
        std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_ad << " points of damage!\n";
    else
        std::cout << "Not enough EP left to perform this action.\n";
    this->_ep--;
}

void ClapTrap::takeDamage( unsigned int amount ) {
    if ( this->_hp <= 0 ) {
        std::cout << "ClapTrap " << this->_name << " is already dead!\n";
        return;
    } else {
        this->_hp -= amount;
        std::cout << "ClapTrap " << this->_name << " has been attacked and lost " << amount << " HP!\n";
        if ( this->_hp <= 0 )
            std::cout << "ClapTrap " << this->_name << " has died!\n";
    }
}

void ClapTrap::beRepaired( unsigned int amount ) {
    if ( this->_hp <= 0 ) {
        std::cout << "ClapTrap " << this->_name << " is already dead!\n";
        return;
    } else if ( this->_ep > 0 ) {
        this->_hp += amount;
        std::cout << "ClapTrap " << this->_name << " repairs itself and gains " << amount << " HP back!\n";

    } else
        std::cout << "Not enough EP left to perform this action.\n";
    this->_ep--;
}

std::ostream & operator<<( std::ostream & o, ClapTrap const & c ) {
    o << "ClapTrap: " << c.getName() << " | HP: " << c.getHp() << ", EP: " << c.getEp() << ", AD: " << c.getAd();
    return o;
}

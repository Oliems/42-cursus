/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:57:02 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/21 15:24:17 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character()
    : _name( "Default" ) {
    for ( int i = 0; i < this->_inventorySize; i++ )
        this->_inventory[ i ] = NULL;
}

Character::Character( const std::string & name )
    : _name( name ) {
    for ( int i = 0; i < this->_inventorySize; i++ )
        this->_inventory[ i ] = NULL;
}

Character::Character( Character const & o ) {
    this->_name = o._name;
    for ( int i = 0; i < this->_inventorySize; i++ ) {
        if ( this->_inventory[ i ] )
            delete this->_inventory[ i ];
        if ( o._inventory[ i ] )
            this->_inventory[ i ] = o._inventory[ i ]->clone();
        else
            this->_inventory[ i ] = NULL;
    }
}

Character::~Character() {
    for ( int i = 0; i < this->_inventorySize; i++ )
        if ( this->_inventory[ i ] )
            delete this->_inventory[ i ];
}

Character & Character::operator=( Character const & o ) {
    this->_name = o._name;
    for ( int i = 0; i < this->_inventorySize; i++ ) {
        if ( this->_inventory[ i ] )
            delete this->_inventory[ i ];
        if ( o._inventory[ i ] )
            this->_inventory[ i ] = o._inventory[ i ]->clone();
        else
            this->_inventory[ i ] = NULL;
    }
    return *this;
}

const std::string & Character::getName() const {
    return this->_name;
}

void Character::equip( AMateria * m ) {
    for ( int i = 0; i < this->_inventorySize; i++ ) {
        if ( this->_inventory[ i ] == NULL ) {
            this->_inventory[ i ] = m;
            std::cout << this->_name << " equips " << m->getType() << " in slot " << i << ".\n";
            return;
        }
    }
    std::cout << this->_name << " cannot equip " << m->getType() << " because inventory is full.\n";
    delete m;
}

void Character::unequip( int p_idx ) {
    if ( p_idx >= 0 && p_idx < this->_inventorySize ) {
        std::cout << this->_name << " unequips " << this->_inventory[ p_idx ]->getType() << " (" << p_idx << ").\n";
        this->_inventory[ p_idx ] = NULL;
    }
}

void Character::use( int idx, ICharacter & target ) {
    if ( idx >= 0 && idx < this->_inventorySize && this->_inventory[ idx ] )
        this->_inventory[ idx ]->use( target );
    else
        std::cout << this->_name << " doesn't do anything.\n";
}

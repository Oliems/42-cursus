/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:12:56 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/21 15:17:24 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for ( int i = 0; i < this->_inventory_size; i++ )
        this->_inventory[ i ] = NULL;
}

MateriaSource::MateriaSource( MateriaSource const & o ) {
    for ( int i = 0; i < this->_inventory_size; i++ ) {
        if ( this->_inventory[ i ] )
            delete this->_inventory[ i ];
        if ( o._inventory[ i ] )
            this->_inventory[ i ] = o._inventory[ i ]->clone();
        else
            this->_inventory[ i ] = NULL;
    }
}

MateriaSource::~MateriaSource() {
    for ( int i = 0; i < this->_inventory_size; i++ )
        if ( this->_inventory[ i ] )
            delete this->_inventory[ i ];
}

MateriaSource & MateriaSource::operator=( MateriaSource const & o ) {
    for ( int i = 0; i < this->_inventory_size; i++ ) {
        if ( this->_inventory[ i ] )
            delete this->_inventory[ i ];
        if ( o._inventory[ i ] )
            this->_inventory[ i ] = o._inventory[ i ]->clone();
        else
            this->_inventory[ i ] = NULL;
    }
    return *this;
}

void MateriaSource::learnMateria( AMateria * materia ) {
    for ( int i = 0; i < this->_inventory_size; i++ ) {
        if ( this->_inventory[ i ] == NULL ) {
            std::cout << "MateriaSource learning " << materia->getType() << "\n";
            this->_inventory[ i ] = materia;
            return;
        }
    }

    std::cout << "Inventory is full, materia will be deleted.\n";
    delete materia;
}

AMateria * MateriaSource::createMateria( const std::string & type ) {
    for ( int i = 0; i < this->_inventory_size; i++ )
        if ( this->_inventory[ i ] != NULL && this->_inventory[ i ]->getType() == type )
            return this->_inventory[ i ]->clone();

    std::cout << "Materia need to be learned first.\n";
    return NULL;
}

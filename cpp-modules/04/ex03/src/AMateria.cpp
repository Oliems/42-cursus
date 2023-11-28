/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:05:15 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/21 15:11:37 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void )
    : _type( "none" ) {
}

AMateria::AMateria( std::string const & type )
    : _type( type ) {
}

AMateria::AMateria( AMateria const & o ) {
    this->_type = o._type;
}

AMateria::~AMateria() {
}

AMateria & AMateria::operator=( AMateria const & o ) {
    this->_type = o._type;
    return *this;
}

std::string const & AMateria::getType() const {
    return this->_type;
}

void AMateria::use( ICharacter & target ) {
    ( void )target;
}

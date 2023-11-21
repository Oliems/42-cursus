/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:09:15 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/21 12:25:10 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>
#include <string>

Cure::Cure() {
    this->_type = "cure";
}

Cure::Cure( Cure const & o ) {
    this->_type = o._type;
}

Cure::~Cure() {
}

Cure & Cure::operator=( Cure const & o ) {
    this->_type = o._type;
    return *this;
}

Cure * Cure::clone() const {
    return new Cure( *this );
}

void Cure::use( ICharacter & target ) {
    std::cout << " * heals " << target.getName() << "'s wounds *\n";
}

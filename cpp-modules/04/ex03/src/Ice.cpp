/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:09:15 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/21 12:25:01 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>
#include <string>

Ice::Ice() {
    this->_type = "ice";
}

Ice::Ice( Ice const & o ) {
    this->_type = o._type;
}

Ice::~Ice() {
}

Ice & Ice::operator=( Ice const & o ) {
    this->_type = o._type;
    return *this;
}

Ice * Ice::clone() const {
    return new Ice( *this );
}

void Ice::use( ICharacter & target ) {
    std::cout << " * shoots an ice bolt at " << target.getName() << " *\n";
}

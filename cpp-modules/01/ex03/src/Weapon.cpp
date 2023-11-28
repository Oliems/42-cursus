/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:21:30 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/28 10:28:28 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type )
    : _type( type ) {
}
Weapon::~Weapon() { }

const std::string & Weapon::getType() const {
    return this->_type;
}

void Weapon::setType( std::string type ) {
    this->_type = type;
}

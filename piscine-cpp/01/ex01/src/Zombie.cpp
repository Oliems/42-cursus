/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:05:26 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/27 14:48:58 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie( void ) { }
Zombie::~Zombie() {
    std::cout << this->_name << " has died.\n";
}

void Zombie::announce( void ) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName( std::string name ) {
    this->_name = name;
}

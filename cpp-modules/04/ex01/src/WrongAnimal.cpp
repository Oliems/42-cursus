/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:11:53 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/20 16:37:28 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal: Default constructor used.\n";
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal( std::string type )
    : type( type ) {
    std::cout << "WrongAnimal: Constructor with `type' parameter used.\n";
}

WrongAnimal::WrongAnimal( WrongAnimal const & o )
    : type( o.type ) {
    std::cout << "WrongAnimal: Copy constructor used.\n";
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal: Destructor used.\n";
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & o ) {
    std::cout << "WrongAnimal: Assignement operator used.\n";
    this->type = o.type;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "...\n";
}

std::string WrongAnimal::getType() const {
    return this->type;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:11:53 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/29 12:38:47 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
    std::cout << "Animal: Default constructor used.\n";
    this->type = "Animal";
}

Animal::Animal( std::string type )
    : type( type ) {
    std::cout << "Animal: Constructor with `type' parameter used.\n";
}

Animal::Animal( Animal const & o ) {
    std::cout << "Animal: Copy constructor used.\n";
    *this = o;
}

Animal::~Animal() {
    std::cout << "Animal: Destructor used.\n";
}

Animal & Animal::operator=( Animal const & o ) {
    std::cout << "Animal: Assignement operator used.\n";
    this->type = o.type;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "...\n";
}

std::string Animal::getType() const {
    return this->type;
}

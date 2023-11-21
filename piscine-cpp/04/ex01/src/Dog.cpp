/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:11:56 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/29 12:30:27 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() {
    std::cout << "Dog: Default constructor used.\n";
    this->type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog( Dog const & o ) {
    *this = o;
    std::cout << "Dog: Copy constructor used.\n";
}

Dog::~Dog() {
    std::cout << "Dog: Destructor used.\n";
    delete this->_brain;
}

Dog & Dog::operator=( const Dog & o ) {
    std::cout << "Dog: Assignement operator used.\n";
    this->type = o.type;
    this->_brain = new Brain( *o._brain );
    return *this;
}

void Dog::makeSound( void ) const {
    std::cout << "Woof!\n";
}

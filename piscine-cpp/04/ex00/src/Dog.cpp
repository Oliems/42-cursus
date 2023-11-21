/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:11:56 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/20 16:41:59 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() {
    std::cout << "Dog: Default constructor used.\n";
    this->type = "Dog";
}

Dog::Dog( Dog const & o ) {
    this->type = o.type;
    std::cout << "Dog: Copy constructor used.\n";
}

Dog::~Dog( void ) {
    std::cout << "Dog: Destructor used.\n";
}

Dog & Dog::operator=( const Dog & o ) {
    std::cout << "Car: Assignement operator used.\n";
    this->type = o.type;
    return *this;
}

void Dog::makeSound( void ) const {
    std::cout << "Woof!\n";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:11:56 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/29 12:30:51 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

Cat::Cat() {
    std::cout << "Cat: Default constructor used.\n";
    this->type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat( Cat const & o ) {
    *this = o;
    std::cout << "Cat: Copy constructor used.\n";
}

Cat::~Cat() {
    std::cout << "Cat: Destructor used.\n";
    delete this->_brain;
}

Cat & Cat::operator=( const Cat & o ) {
    std::cout << "Cat: Assignement operator used.\n";
    this->type = o.type;
    this->_brain = new Brain( *o._brain );
    return *this;
}

void Cat::makeSound( void ) const {
    std::cout << "Meow!\n";
}

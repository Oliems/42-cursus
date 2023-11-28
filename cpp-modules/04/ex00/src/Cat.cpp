/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:11:56 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/20 17:21:19 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() {
    std::cout << "Cat: Default constructor used.\n";
    this->type = "Cat";
}

Cat::Cat( Cat const & o ) {
    this->type = o.type;
    std::cout << "Cat: Copy constructor used.\n";
}

Cat::~Cat( void ) {
    std::cout << "Cat: Destructor used.\n";
}

Cat & Cat::operator=( const Cat & o ) {
    std::cout << "Cat: Assignement operator used.\n";
    this->type = o.type;
    return *this;
}

void Cat::makeSound( void ) const {
    std::cout << "Meow!\n";
}

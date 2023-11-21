/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:11:56 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/20 16:27:56 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat() {
    std::cout << "Default WrongCat constructor used.\n";
    this->type = "WrongCat";
}

WrongCat::WrongCat( WrongCat const & o ) {
    this->type = o.type;
    std::cout << "WrongCat: Copy constructor used.\n";
}

WrongCat::~WrongCat( void ) {
    std::cout << "WrongCat: Destructor used.\n";
}

WrongCat & WrongCat::operator=( const WrongCat & o ) {
    std::cout << "Car: Assignement operator used.\n";
    this->type = o.type;
    return *this;
}

void WrongCat::makeSound( void ) const {
    std::cout << "WrongCat: Meow! \n";
}

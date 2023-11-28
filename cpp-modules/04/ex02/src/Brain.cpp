/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:04:08 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/29 12:30:58 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << "Brain: Default constructor used.\n";
    for ( int i = 0; i < BRAIN_SIZE; i++ )
        this->_ideas[ i ] = "";
}

Brain::~Brain() {
    std::cout << "Brain: Destructor used.\n";
}

Brain::Brain( Brain const & o ) {
    std::cout << "Brain: Copy constructor used.\n";
    *this = o;
}

Brain & Brain::operator=( Brain const & o ) {
    std::cout << "Brain: Assigment operator used.\n";
    for ( int i = 0; i < 100; i++ )
        this->_ideas[ i ] = o._ideas[ i ];
    return *this;
}

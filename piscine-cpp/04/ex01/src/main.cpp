/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:49:01 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/29 12:35:01 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main( void ) {
    const Animal * j = new Dog();
    const Animal * i = new Cat();

    delete j;
    delete i;

    Dog basic;
    {
        Dog tmp = basic;
    }

    const Animal * animals[ 4 ] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ ) {
        delete animals[ i ];
    }

    return 0;
}

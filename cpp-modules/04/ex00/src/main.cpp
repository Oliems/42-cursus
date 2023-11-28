/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:49:01 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/28 15:04:44 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main( void ) {
    std::cout << "SUBJECT TESTS\n";
    const Animal * cat = new Cat();
    const Animal * dog = new Dog();
    const Animal * animal = new Animal();
    std::cout << cat->getType() << "\n";
    std::cout << dog->getType() << "\n";
    cat->makeSound();
    dog->makeSound();
    animal->makeSound();
    delete cat, delete dog, delete animal;

    std::cout << "\n";

    std::cout << "BASIC TESTS\n";
    Animal ani = Animal();
    ani.makeSound();
    ani = Cat();
    std::cout << ani.getType() << ": ";
    ani.makeSound();

    std::cout << "\n";

    std::cout << "WRONG CLASSES TESTS\n";
    const WrongAnimal * wani = new WrongAnimal();
    const WrongAnimal * wcat = new WrongCat();

    std::cout << wani->getType() << "\n";
    wani->makeSound();
    std::cout << wcat->getType() << "\n";
    wcat->makeSound();

    delete wani, delete wcat;
    std::cout << "\n";
    return 0;
}

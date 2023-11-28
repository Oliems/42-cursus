/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:11:47 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/20 17:19:11 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog( const Dog & o );
    virtual ~Dog( void );
    Dog & operator=( const Dog & o );

    virtual void makeSound( void ) const;

private:
    Brain * _brain;
};

#endif

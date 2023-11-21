/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:11:20 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/20 15:49:11 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
    Animal();
    Animal( std::string type );
    Animal( Animal const & o );
    virtual ~Animal();

    Animal & operator=( Animal const & o );

    virtual void makeSound() const;
    std::string getType() const;

protected:
    std::string type;
};

#endif

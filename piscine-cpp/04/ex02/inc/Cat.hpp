/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:11:44 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/20 17:18:38 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat( const Cat & o );
    virtual ~Cat( void );
    Cat & operator=( const Cat & o );

    virtual void makeSound( void ) const;

private:
    Brain * _brain;
};

#endif

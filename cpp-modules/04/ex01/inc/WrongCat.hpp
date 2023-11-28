/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:34:55 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/20 16:43:14 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat( const WrongCat & o );
    virtual ~WrongCat();
    WrongCat & operator=( const WrongCat & o );

    void makeSound( void ) const;
};

#endif

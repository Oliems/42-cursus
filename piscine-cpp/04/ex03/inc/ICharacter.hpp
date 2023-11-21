/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:08:17 by ocartier          #+#    #+#             */
/*   Updated: 2023/08/21 14:57:43 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"
#include <iostream>

class AMateria;

class ICharacter {
public:
    virtual ~ICharacter() { }
    virtual const std::string & getName() const = 0;
    virtual void equip( AMateria * m ) = 0;
    virtual void unequip( int idx ) = 0;
    virtual void use( int idx, ICharacter & target ) = 0;
};

#endif

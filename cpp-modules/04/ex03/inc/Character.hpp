/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:56:02 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/21 14:55:59 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
    Character();
    Character( const std::string & name );
    Character( const Character & src );
    virtual ~Character();

    Character & operator=( const Character & src );

    const std::string & getName() const;
    void equip( AMateria * m );
    void unequip( int idx );
    void use( int idx, ICharacter & target );

protected:
    static const int _inventorySize = 4;
    AMateria * _inventory[ _inventorySize ];
    std::string _name;
};

#endif

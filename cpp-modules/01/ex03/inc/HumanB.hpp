/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:26:45 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/28 10:28:46 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
public:
    HumanB( std::string name );
    ~HumanB();

    void attack();
    const std::string & getName() const;
    void setWeapon( Weapon & weapon );

private:
    std::string _name;
    Weapon * _weapon;
};

#endif

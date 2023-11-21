/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:26:42 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/28 10:28:39 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
public:
    HumanA( std::string name, Weapon & weapon );
    ~HumanA();

    void attack();
    const std::string & getName() const;

private:
    std::string _name;
    Weapon & _weapon;
};

#endif

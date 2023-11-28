/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:19:00 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/28 10:27:31 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public:
    Weapon( std::string type );
    ~Weapon();

    const std::string & getType() const;
    void setType( std::string type );

private:
    std::string _type;
};

#endif

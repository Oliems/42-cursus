/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:23:45 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 16:02:31 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
public:
    DiamondTrap();
    DiamondTrap( std::string const & name );
    DiamondTrap( DiamondTrap const & o );
    virtual ~DiamondTrap();

    DiamondTrap & operator=( DiamondTrap const & o );

    void whoAmI();

private:
    std::string _name;
};

std::ostream & operator<<( std::ostream & o, DiamondTrap const & c );

#endif

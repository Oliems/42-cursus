/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:56:24 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 15:11:02 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
public:
    ScavTrap();
    ScavTrap( std::string const & name );
    ScavTrap( ScavTrap const & o );
    virtual ~ScavTrap();

    ScavTrap & operator=( ScavTrap const & o );

    void attack( const std::string & target );
    bool getGuarding() const;
    void guardGate();

private:
    bool _guarding;
};

std::ostream & operator<<( std::ostream & o, ScavTrap const & c );

#endif

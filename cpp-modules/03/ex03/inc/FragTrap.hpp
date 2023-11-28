/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:56:24 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 15:32:42 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap {
public:
    FragTrap();
    FragTrap( std::string const & name );
    FragTrap( FragTrap const & o );
    virtual ~FragTrap();

    FragTrap & operator=( FragTrap const & o );

    void highFivesGuys( void );
};

std::ostream & operator<<( std::ostream & o, FragTrap const & c );

#endif

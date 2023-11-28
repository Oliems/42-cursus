/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:38:35 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/21 12:23:13 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <string>

class Ice : public AMateria {
public:
    Ice();
    Ice( std::string const & type );
    Ice( Ice const & o );
    virtual ~Ice();

    Ice & operator=( Ice const & o );

    Ice * clone() const;
    void use( ICharacter & target );
};

#endif

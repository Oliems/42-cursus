/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:29:53 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/21 15:04:21 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>

class ICharacter;

class AMateria {
public:
    AMateria();
    AMateria( std::string const & type );
    AMateria( AMateria const & o );
    virtual ~AMateria();

    AMateria & operator=( AMateria const & o );

    std::string const & getType() const;
    virtual AMateria * clone() const = 0;
    virtual void use( ICharacter & target );

protected:
    std::string _type;
};

#endif

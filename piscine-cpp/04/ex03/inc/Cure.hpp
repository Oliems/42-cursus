/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:38:33 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/21 12:23:23 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <string>

class Cure : public AMateria {
public:
    Cure();
    Cure( Cure const & o );
    virtual ~Cure();

    Cure & operator=( Cure const & o );

    Cure * clone() const;
    void use( ICharacter & target );
};

#endif

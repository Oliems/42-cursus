/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:55:06 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/21 14:58:01 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {
public:
    virtual ~IMateriaSource() { }
    virtual void learnMateria( AMateria * ) = 0;
    virtual AMateria * createMateria( std::string const & type ) = 0;
};

#endif

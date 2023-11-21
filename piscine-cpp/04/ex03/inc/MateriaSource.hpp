/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:58:37 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/21 15:21:26 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
protected:
    static const int _inventory_size = 4;
    AMateria * _inventory[ _inventory_size ];

public:
    MateriaSource( void );
    MateriaSource( const MateriaSource & src );
    MateriaSource & operator=( const MateriaSource & src );

    virtual ~MateriaSource();

    void learnMateria( AMateria * m );
    AMateria * createMateria( const std::string & type );
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:34:28 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/20 16:43:12 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal( std::string type );
    WrongAnimal( const WrongAnimal & o );
    virtual ~WrongAnimal();
    WrongAnimal & operator=( const WrongAnimal & o );

    std::string getType( void ) const;
    void makeSound( void ) const;

protected:
    std::string type;
};

#endif

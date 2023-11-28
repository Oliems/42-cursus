/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:54:02 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/21 15:25:04 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main( void ) {
    IMateriaSource * src = new MateriaSource();

    src->learnMateria( new Ice() );
    src->learnMateria( new Cure() );

    ICharacter * john = new Character( "John" );
    AMateria * tmp;

    tmp = src->createMateria( "ice" );
    john->equip( tmp );
    tmp = src->createMateria( "cure" );
    john->equip( tmp );

    john->equip( src->createMateria( "cure" ) );
    john->equip( src->createMateria( "cure" ) );
    john->equip( src->createMateria( "cure" ) );

    tmp = src->createMateria( "ETHER" );
    ICharacter * bob = new Character( "bob" );
    john->use( 0, *bob );
    john->use( 1, *bob );

    delete bob, delete john, delete src;
    return 0;
}

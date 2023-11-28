/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:05:19 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/27 14:17:24 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie * newZombie( std::string name );
void randomChump( std::string name );

int main( void ) {
    Zombie z1 = Zombie( "Bob" );
    Zombie * z2 = newZombie( "Alice" );
    randomChump( "Charles" );
    delete z2;
    return 0;
}

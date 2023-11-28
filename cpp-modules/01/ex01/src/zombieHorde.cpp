/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:20:23 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/27 14:49:07 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie * zombieHorde( int N, std::string name ) {
    Zombie * z = new Zombie[ N ];
    for ( int i = 0; i < N; i++ ) {
        z[ i ].setName( name );
        z[ i ].announce();
    }
    return z;
}

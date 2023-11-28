/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:05:19 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/27 14:48:54 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie * zombieHorde( int N, std::string name );

int main( void ) {
    int N = 6;
    Zombie * horde = zombieHorde( N, "Bob" );
    delete[] horde;
    return 0;
}

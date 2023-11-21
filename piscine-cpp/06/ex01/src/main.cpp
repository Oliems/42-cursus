/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:30:46 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/31 12:14:16 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main( void ) {
    Data d = { "John", 30, 185, 80, true };
    std::cout << d.name << " " << d.age << " " << d.height << " " << d.weight << " " << d.single << "\n";
    Data * dptr = Serializer::deserialize( Serializer::serialize( &d ) );
    std::cout << dptr->name << " " << dptr->age << " " << dptr->height << " " << dptr->weight << " " << dptr->single << "\n";
    if ( &d == dptr )
        std::cout << "OK\n";
    else
        std::cout << "KO\n";
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:23:26 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/28 14:52:02 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main( void ) {
    Harl h;

    h.complain( "DEBUG" );
    h.complain( "INFO" );
    h.complain( "WARNING" );
    h.complain( "ERROR" );
    h.complain( "NULL" );
    return 0;
}

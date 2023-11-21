/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:09:57 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/30 18:16:18 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base * generate( void ) {
    int num = rand() % 3 + 1;
    switch ( num ) {
    case 1:
        return new A;
    case 2:
        return new B;
    case 3:
        return new C;
    }
    return NULL;
}

void identify( Base * p ) {
    if ( dynamic_cast<A *>( p ) )
        std::cout << "(identify Base *) -> A.\n";
    else if ( dynamic_cast<B *>( p ) )
        std::cout << "(identify Base *) -> B.\n";
    else if ( dynamic_cast<C *>( p ) )
        std::cout << "(identify Base *) -> C.\n";
    else
        std::cout << "(identify Base *) Can't identify this Base *.\n";
}

void identify( Base & p ) {
    try {
        ( void )dynamic_cast<A &>( p );
        std::cout << "(identify Base &) -> A.\n";
        return;
    } catch ( std::exception & e ) {
        ( void )e;
    }
    try {
        ( void )dynamic_cast<B &>( p );
        std::cout << "(identify Base &) -> B.\n";
        return;
    } catch ( std::exception & e ) {
        ( void )e;
    }
    try {
        ( void )dynamic_cast<C &>( p );
        std::cout << "(identify Base &) -> C.\n";
        return;
    } catch ( std::exception & e ) {
        ( void )e;
    }
    std::cout << "(identify Base &) Can't identify this Base &.\n";
}

int main( void ) {
    srand( ( unsigned int )time( NULL ) );
    for ( int i = 0; i < 5; i++ ) {
        Base * b = generate();
        identify( b );
        identify( *b );
        delete b;
    }
    return 0;
}

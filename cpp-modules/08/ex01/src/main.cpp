/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:52:27 by mbarberi          #+#    #+#             */
/*   Updated: 2023/09/06 10:21:02 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <iostream>
#include <stdlib.h>

int main( void ) {
    Span test( 3 );
    std::cout << "--- Shortest span with empty Span ---\n";
    try {
        test.shortestSpan();
    } catch ( const std::exception & e ) {
        std::cerr << e.what() << '\n';
    }
    test.addNumber( 1 );
    std::cout << "\n--- Longest span with Span with one element ---\n";
    try {
        test.longestSpan();
    } catch ( const std::exception & e ) {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n--- Adding too many elements in Span with addNumber() ---\n";
    try {
        test.addNumber( 2 );
        test.addNumber( 3 );
        test.addNumber( 4 );
    } catch ( const std::exception & e ) {
        std::cerr << e.what() << '\n';
    }
    Span test1( 5 );
    std::cout << "\n--- Adding too many elements in Span with addRange() ---\n";
    try {
        test1.addRange( 6 );
    } catch ( const std::exception & e ) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n--- Test using addRange and n = 100000 ---\n";
    unsigned int n = 100000;
    srand( unsigned( std::time( NULL ) ) );
    Span sp( n );
    sp.addRange( n );
    std::cout << "shortest span: " << sp.shortestSpan() << "\n";
    std::cout << "longest span: " << sp.longestSpan() << "\n";

    std::cout << "\n--- Test using addNumber and n = 5 ---\n";
    n = 5;
    Span sp1( n );
    sp1.addNumber( 6 );
    sp1.addNumber( 3 );
    sp1.addNumber( 17 );
    sp1.addNumber( 9 );
    sp1.addNumber( 11 );
    std::cout << "shortest span: " << sp1.shortestSpan() << "\n";
    std::cout << "longest span: " << sp1.longestSpan() << "\n";
    return 0;
}

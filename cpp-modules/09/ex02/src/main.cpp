/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:01:58 by mbarberi          #+#    #+#             */
/*   Updated: 2023/10/30 10:49:48 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

/*
 * Here we chose to use the vector and the deque since both implement the
 * '[]' operator which allows us to use templates when implementing the
 * algortihm.
 *
 * However the underlying implementation of the vector and deque classes
 * are different which explains the difference in speed. As opposed to
 * std::vector, the elements of a deque are not stored contiguously:
 * typical implementations use a sequence of individually allocated
 * fixed-size arrays, with additional bookkeeping, which means indexed
 * access to deque must perform two pointer dereferences, compared to
 * vector's indexed access which performs only one.
 */
int main( int argc, char ** argv ) {
    if ( argc < 2 ) {
        std::cout << "Usage: ./PmergeMe sequence\n";
        return 1;
    }

    int n;
    std::deque<int> d;
    std::vector<int> v;
    for ( int i = 1; i < argc; i++ ) {
        std::stringstream ss( argv[ i ] );
        if ( !( ss >> n ) || !ss.eof() ) {
            std::cout << "Error: Invalid input.\n";
            return 1;
        }
        if ( n < 0 ) {
            std::cout << "Error: Negative numbers are not allowed.\n";
            return 1;
        }
        v.push_back( n );
        d.push_back( n );
    }
    std::cout << "Before: ";
    print_container( v );
    double tv = bench_container( v );
    double td = bench_container( d );
    std::cout << "\nAfter: ";
    print_container( v );
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << tv << " us\n";
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque : " << td << " us\n";
    return 0;
}

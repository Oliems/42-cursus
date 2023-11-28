/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:01:51 by mbarberi          #+#    #+#             */
/*   Updated: 2023/09/17 11:15:41 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <deque>
#include <iostream>
#include <vector>

#define THRESHOLD 10

template <class T>
static void insert_sort( T & c, int start, int end ) {
    for ( int i = start + 1; i <= end; i++ ) {
        int key = c[ i ]; /* store the element to be placed in the correct position */
        int j = i - 1;
        for ( ; j >= start && c[ j ] > key; j-- )
            c[ j + 1 ] = c[ j ]; /* shift all elements to the right by 1 */
        c[ j + 1 ] = key;        /* insert the element in the correct position */
    }
}

template <class T>
static void merge( T & c, int start, int mid, int end ) {
    int n1 = mid - start + 1; /* compute the size of the 'subarrays' */
    int n2 = end - mid;

    T left( n1 ), right( n2 );     /* create temporary 'arrays' */

    for ( int i = 0; i < n1; i++ ) /* copy elements from the original 'array' */
        left[ i ] = c[ start + i ];
    for ( int j = 0; j < n2; j++ )
        right[ j ] = c[ mid + 1 + j ];

    int i = 0, j = 0, k = start;
    /* compare elements from the 'subarrays' and merge them in order in the original array */
    while ( i < n1 && j < n2 ) {
        if ( left[ i ] <= right[ j ] )
            c[ k++ ] = left[ i++ ];
        else
            c[ k++ ] = right[ j++ ];
    }
    /* copy any remaining elements from the left or right array to the original array c. */
    while ( i < n1 )
        c[ k++ ] = left[ i++ ];
    while ( j < n2 )
        c[ k++ ] = right[ j++ ];
}

template <class T>
static void merge_insert_sort( T & c, int start, int end ) {
    if ( start < end ) {
        /* check if the subarray is small enough to be sorted using an insertion sort */
        if ( end - start < THRESHOLD ) {
            insert_sort( c, start, end );
        } else {
            int mid = start + ( end - start ) / 2;
            merge_insert_sort( c, start, mid );   /* sort left half */
            merge_insert_sort( c, mid + 1, end ); /* sort right half */
            merge( c, start, mid, end );          /* merge the two sorted halves */
        }
    }
}

template <class T>
void print_container( const T & c ) {
    for ( typename T::const_iterator it = c.begin(); it != c.end(); it++ )
        std::cout << *it << " ";
    std::cout << '\n';
}

template <class T>
double bench_container( T & c ) {
    std::clock_t start = std::clock();
    merge_insert_sort( c, 0, c.size() - 1 );
    std::clock_t end = std::clock();
    double elapsed = 1000000.0 * ( end - start ) / CLOCKS_PER_SEC;
    return elapsed;
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:21:18 by mbarberi          #+#    #+#             */
/*   Updated: 2023/09/04 11:27:57 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

/* class Awesome {
public:
    Awesome(void)
        : _n(42)
    {
    }
    int get(void) const { return this->_n; }

private:
    int _n;
};

std::ostream & operator<<(std::ostream & o, Awesome const & rhs)
{
    o << rhs.get();
    return o;
}

template <typename T>
void print(T & x) { std::cout << x << "\n"; }

int main(void)
{
    int tab[] = { 0, 1, 2, 3, 4 };
    Awesome tab2[5];
    iter(tab, 5, print);
    iter(tab2, 5, print);
    return 0;
} */

template <typename T>
void echo( T & o ) {
    std::cout << "--- " << o << " ---\n";
}

template <>
void echo<std::string>( std::string & o ) {
    std::cout << "*** " << o << " ***\n";
}

int main( void ) {
    int int_arr[ 5 ] = { 1, 2, 3, 4, 5 };
    std::string str_arr[ 5 ] = { "one", "two", "three", "four", "five" };

    iter<int>( int_arr, 5, echo );
    std::cout << "\n";
    iter( str_arr, 5, echo );

    return 0;
}

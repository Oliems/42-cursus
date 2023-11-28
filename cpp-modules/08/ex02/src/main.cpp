/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:34:11 by mbarberi          #+#    #+#             */
/*   Updated: 2023/09/05 19:57:36 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <string>

#include "MutantStack.hpp"

int main( int, char ** ) {
    {
        std::cout << "MutantStack\n";
        MutantStack<int> mstack;

        mstack.push( 5 );
        mstack.push( 17 );
        std::cout << mstack.top() << '\n';
        mstack.pop();
        std::cout << mstack.size() << '\n';
        mstack.push( 3 );
        mstack.push( 5 );
        mstack.push( 737 );
        mstack.push( 0 );
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while ( it != ite ) {
            std::cout << *it << '\n';
            ++it;
        }
        std::stack<int> s( mstack );
    }
    {
        std::cout << "Native lists\n";
        std::list<int> mstack;

        mstack.push_back( 5 );
        mstack.push_back( 17 );
        std::cout << mstack.back() << '\n';
        mstack.pop_back();
        std::cout << mstack.size() << '\n';
        mstack.push_back( 3 );
        mstack.push_back( 5 );
        mstack.push_back( 737 );
        mstack.push_back( 0 );
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while ( it != ite ) {
            std::cout << *it << '\n';
            it++;
        }
    }
    return 0;
}

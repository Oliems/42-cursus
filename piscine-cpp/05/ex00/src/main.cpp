/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:47:01 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/21 17:15:41 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

int main( void ) {
    Bureaucrat bob( "Bob", 3 );
    try {
        for ( int i = 0; i < 3; i++ ) {
            std::cout << bob;
            bob.promote();
        }
    } catch ( Bureaucrat::GradeTooHighException & e ) {
        std::cout << e.what();
    }

    std::cout << "\n";
    Bureaucrat bob_cpy( bob );
    std::cout << bob_cpy;
    std::cout << "\n";

    Bureaucrat alice( "Alice", 148 );
    try {
        for ( int i = 0; i < 3; i++ ) {
            std::cout << alice;
            alice.demote();
        }
    } catch ( Bureaucrat::GradeTooLowException & e ) {
        std::cout << e.what();
    }

    std::cout << "\n";
    bob_cpy = alice;
    std::cout << bob_cpy;
    std::cout << "\n";

    try {
        Bureaucrat john( "John", 151 );
        std::cout << john;
    } catch ( std::exception & e ) {
        std::cout << e.what();
    }
    return 0;
}

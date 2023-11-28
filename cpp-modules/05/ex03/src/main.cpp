/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:47:01 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/29 20:07:12 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

int main() {
    Intern machin;
    Bureaucrat bob = Bureaucrat( "Bob", 3 );
    Bureaucrat alice = Bureaucrat( "Alice", 150 );
    Bureaucrat john = Bureaucrat( "John", 20 );

    AForm * f1 = machin.makeForm( "shrubbery creation", "trailer" );
    AForm * f2 = machin.makeForm( "robotomy request", "Ricky" );
    AForm * f3 = machin.makeForm( "presidential pardon", "Julian" );
    machin.makeForm( "test", "test" );

    std::cout << "\n";
    if ( f1 ) {
        bob.executeForm( *f1 );
        alice.signForm( *f1 );
        bob.signForm( *f1 );
        alice.executeForm( *f1 );
        bob.executeForm( *f1 );
    }

    std::cout << "\n";
    if ( f2 ) {
        john.signForm( *f2 );
        john.executeForm( *f2 );
    }

    std::cout << "\n";
    if ( f3 ) {
        john.signForm( *f3 );
        john.executeForm( *f3 );
        bob.executeForm( *f3 );
    }
    delete f1, delete f2, delete f3;
    return 0;
}

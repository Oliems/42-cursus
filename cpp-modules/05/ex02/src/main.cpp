/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:47:01 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/22 19:27:43 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

int main() {
    Bureaucrat bob( "Bob", 3 );
    Bureaucrat alice( "Alice", 150 );
    Bureaucrat john( "John", 20 );

    ShrubberyCreationForm f1( "home" );
    RobotomyRequestForm f2( "Intern" );
    PresidentialPardonForm f3( "Jack" );

    bob.executeForm( f1 );
    alice.signForm( f1 );
    bob.signForm( f1 );
    alice.executeForm( f1 );
    bob.executeForm( f1 );

    std::cout << "\n";
    john.signForm( f2 );
    john.executeForm( f2 );
    john.executeForm( f2 );
    john.executeForm( f2 );
    john.executeForm( f2 );

    std::cout << "\n";
    john.signForm( f3 );
    john.executeForm( f3 );

    PresidentialPardonForm f4 = f3;
    bob.signForm( f4 );
    bob.executeForm( f4 );

    return 0;
}

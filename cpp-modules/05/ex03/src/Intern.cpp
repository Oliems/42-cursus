/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:32:34 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/24 15:14:39 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

Intern::Intern( void ) {
}

Intern::Intern( const Intern & src ) {
    *this = src;
}

Intern::~Intern( void ) {
}

Intern & Intern::operator=( const Intern & src ) {
    ( void )src;
    return *this;
}

static AForm * createShrubbery( const std::string target ) {
    return ( new ShrubberyCreationForm( target ) );
}

static AForm * createRobotomy( const std::string target ) {
    return ( new RobotomyRequestForm( target ) );
}

static AForm * createPresident( const std::string target ) {
    return ( new PresidentialPardonForm( target ) );
}

AForm * Intern::makeForm( std::string name, std::string target ) {
    AForm * createdForm = NULL;
    const std::string formsNames[] = { "shrubbery creation", "robotomy request", "presidential pardon" };
    AForm * ( *formsFun[] )( std::string target ) = { &createShrubbery, &createRobotomy, &createPresident };

    for ( int i = 0; i < 3; i++ ) {
        if ( name == formsNames[ i ] ) {
            createdForm = formsFun[ i ]( target );
            break;
        }
    }
    if ( !createdForm )
        std::cout << "There is no form with the name \"" << name << "\", but I can do the following forms : \"shrubbery creation\", \"robotomy creation\", \"presidential pardon\".\n";
    return createdForm;
}

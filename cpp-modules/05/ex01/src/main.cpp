/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:47:01 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/29 19:52:37 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

int main( void ) {
    std::cout << "Create a form with incorect signGrade: ";
    try {
        Form fa = Form( "fa", 0, 150 );
    } catch ( std::exception & e ) {
        std::cout << e.what();
    }
    std::cout << "Create a form with incorect execGrade: ";
    try {
        Form fb = Form( "fb", 1, 151 );
    } catch ( std::exception & e ) {
        std::cout << e.what();
    }

    Form f1( "f1", 1, 1 );
    Bureaucrat alice( "Alice", 1 );

    std::cout << "\n";
    std::cout << f1;
    std::cout << "SignForm: Success: ";
    try {
        alice.signForm( f1 );
    } catch ( std::exception & e ) {
        std::cout << e.what();
    }

    std::cout << f1;
    std::cout << "SignForm: Already Signed: ";
    try {
        alice.signForm( f1 );
    } catch ( std::exception & e ) {
        std::cout << e.what();
    }

    Form f2( "f2", 74, 1 );
    Bureaucrat bob( "Bob", 75 );

    std::cout << "\n";
    std::cout << f2;
    std::cout << "SignForm: Failure: ";
    try {
        bob.signForm( f2 );
    } catch ( std::exception & e ) {
        std::cout << e.what();
    }

    bob.promote();

    std::cout << f2;
    std::cout << "SignForm: Success: ";
    try {
        bob.signForm( f2 );
    } catch ( std::exception & e ) {
        std::cout << e.what();
    }
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:56:36 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/22 19:26:10 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm( "Robotomy Request", 72, 45 )
    , _target( "Default" ) {
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
    : AForm( "Robotomy Request", 72, 45 )
    , _target( target ) {
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & o )
    : AForm( "Robotomy Request", 72, 45 )
    , _target( o._target + "_copy" ) {
    *this = o;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & o ) {
    ( void )o;
    return *this;
}

static int test = 1;
void RobotomyRequestForm::beExecuted() const {
    if ( test % 2 )
        std::cout << this->_target << " has been robotomized.\n";
    else
        std::cout << "Oops... The robotomization has failed for " << this->_target << ".\n";
    test++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:16:10 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/22 19:05:04 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm( "Presidential Pardon", 25, 5 )
    , _target( "Default" ) {
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
    : AForm( "Presidential Pardon", 25, 5 )
    , _target( target ) {
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & o )
    : AForm( "Presidential Pardon", 25, 5 )
    , _target( o._target + "_copy" ) {
    *this = o;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & o ) {
    ( void )o;
    return *this;
}

void PresidentialPardonForm::beExecuted() const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}

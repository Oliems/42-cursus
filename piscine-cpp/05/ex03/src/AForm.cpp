/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:21:07 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/22 12:55:00 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

AForm::AForm()
    : _name( "Default" )
    , _signGrade( LOWEST_GRADE )
    , _execGrade( LOWEST_GRADE )
    , _signed( false ) {
}

AForm::AForm( std::string name, int signGrade, int execGrade )
    : _name( name )
    , _signGrade( signGrade )
    , _execGrade( execGrade )
    , _signed( false ) {
    if ( signGrade < HIGHEST_GRADE || execGrade < HIGHEST_GRADE )
        throw AForm::GradeTooHighException();
    else if ( signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE )
        throw AForm::GradeTooLowException();
}

AForm::AForm( AForm const & o )
    : _name( o._name + "_copy" )
    , _signGrade( o._signGrade )
    , _execGrade( o._execGrade )
    , _signed( o._signed ) {
}

AForm::~AForm() {
}

AForm & AForm::operator=( AForm const & o ) {
    this->_signed = o._signed;
    return *this;
}

std::string const & AForm::getName() const {
    return this->_name;
}

int AForm::getSignGrade() const {
    return this->_signGrade;
}

int AForm::getExecGrade() const {
    return this->_execGrade;
}

bool AForm::getSigned() const {
    return this->_signed;
}

void AForm::beSigned( const Bureaucrat b ) {
    if ( b.getGrade() > this->_signGrade )
        throw AForm::GradeTooLowException();
    this->_signed = true;
}

void AForm::execute( Bureaucrat const & executor ) const {
    if ( executor.getGrade() > this->_execGrade )
        throw AForm::GradeTooLowException();
    else if ( !this->_signed )
        throw AForm::FormNotSignedException();
    else
        this->beExecuted();
}

char const * AForm::GradeTooHighException::what() const throw() {
    return ( "Grade is too high for this form.\n" );
}

char const * AForm::GradeTooLowException::what() const throw() {
    return ( "Grade is too low for this form.\n" );
}

const char * AForm::FormNotSignedException::what() const throw() {
    return ( "The form has not been signed.\n" );
}

std::ostream & operator<<( std::ostream & o, const AForm & f ) {
    o << f.getName() << ", grade required to sign: " << f.getSignGrade() << ", grade required to execute: " << f.getExecGrade() << ", status: " << ( f.getSigned() ? "signed" : "not signed" ) << ".\n";
    return o;
}

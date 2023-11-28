/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:21:07 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/22 18:54:04 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Form::Form()
    : _name( "Default" )
    , _signGrade( LOWEST_GRADE )
    , _execGrade( LOWEST_GRADE )
    , _signed( false ) {
}

Form::Form( std::string name, int signGrade, int execGrade )
    : _name( name )
    , _signGrade( signGrade )
    , _execGrade( execGrade )
    , _signed( false ) {
    if ( signGrade < HIGHEST_GRADE || execGrade < HIGHEST_GRADE )
        throw Form::GradeTooHighException();
    else if ( signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE )
        throw Form::GradeTooLowException();
}

Form::Form( Form const & o )
    : _name( o._name + "_copy" )
    , _signGrade( o._signGrade )
    , _execGrade( o._execGrade )
    , _signed( o._signed ) {
}

Form::~Form() {
}

Form & Form::operator=( Form const & o ) {
    this->_signed = o._signed;
    return *this;
}

std::string const & Form::getName() const {
    return this->_name;
}

int Form::getSignGrade() const {
    return this->_signGrade;
}

int Form::getExecGrade() const {
    return this->_execGrade;
}

bool Form::getSigned() const {
    return this->_signed;
}

void Form::beSigned( const Bureaucrat b ) {
    if ( b.getGrade() > this->_signGrade )
        throw Form::GradeTooLowException();
    this->_signed = true;
}

char const * Form::GradeTooHighException::what() const throw() {
    return ( "Grade is too high for this form.\n" );
}

char const * Form::GradeTooLowException::what() const throw() {
    return ( "Grade is too low for this form.\n" );
}

std::ostream & operator<<( std::ostream & o, const Form & f ) {
    o << f.getName() << ", grade required to sign: " << f.getSignGrade() << ", grade required to execute: " << f.getExecGrade() << ", status: " << ( f.getSigned() ? "signed" : "not signed" ) << ".\n";
    return o;
}

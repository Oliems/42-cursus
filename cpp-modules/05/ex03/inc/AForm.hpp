/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:21:09 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/22 19:09:53 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
public:
    AForm();
    AForm( std::string name, int signGrade, int execGrade );
    AForm( AForm const & o );
    virtual ~AForm();

    AForm & operator=( AForm const & o );

    std::string const & getName() const;
    int getSignGrade() const;
    int getExecGrade() const;
    bool getSigned() const;

    void beSigned( Bureaucrat const b );
    void execute( Bureaucrat const & executor ) const;

    class GradeTooHighException : public std::exception {
    public:
        virtual char const * what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual char const * what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char * what( void ) const throw();
    };

private:
    std::string const _name;
    int const _signGrade;
    int const _execGrade;
    bool _signed;

    virtual void beExecuted( void ) const = 0;
};

std::ostream & operator<<( std::ostream & o, AForm const & f );

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:21:09 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/22 12:24:52 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
public:
    Form();
    Form( std::string name, int signGrade, int execGrade );
    Form( Form const & o );
    ~Form();

    Form & operator=( Form const & o );

    std::string const & getName() const;
    int getSignGrade() const;
    int getExecGrade() const;
    bool getSigned() const;

    void beSigned( const Bureaucrat b );

    class GradeTooHighException : public std::exception {
    public:
        virtual char const * what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual char const * what() const throw();
    };

private:
    std::string const _name;
    int const _signGrade;
    int const _execGrade;
    bool _signed;
};

std::ostream & operator<<( std::ostream & o, Form const & f );

#endif

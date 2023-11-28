/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:12:02 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/21 16:51:08 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat {
public:
    Bureaucrat();
    Bureaucrat( std::string name, int grade );
    Bureaucrat( Bureaucrat const & o );
    ~Bureaucrat();

    Bureaucrat & operator=( Bureaucrat const & o );

    std::string const & getName() const;
    int getGrade() const;

    void promote();
    void demote();

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
    int _grade;
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & b );

#endif

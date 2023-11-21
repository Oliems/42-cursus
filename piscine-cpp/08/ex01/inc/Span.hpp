/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:53:03 by mbarberi          #+#    #+#             */
/*   Updated: 2023/09/06 10:11:31 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iostream>
#include <vector>

class Span {
public:
    Span();
    Span( unsigned int n );
    Span( Span const & o );
    ~Span();

    Span & operator=( Span const & o );

    void addNumber( int n );
    void addRange( unsigned int n );
    int shortestSpan();
    int longestSpan();

    std::vector<int> const & getVector( void ) const;

    class MaxSizeReachedException : public std::exception {
    public:
        virtual const char * what( void ) const throw();
    };

    class EmptySpanException : public std::exception {
    public:
        virtual const char * what( void ) const throw();
    };

private:
    unsigned int _n;
    std::vector<int> _v;
};

std::ostream & operator<<( std::ostream & o, const Span & span );

#endif

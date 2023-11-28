/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:52:49 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 09:28:54 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed();
    Fixed( int const x );
    Fixed( float const x );
    Fixed( Fixed const & src );
    ~Fixed();

    Fixed & operator=( Fixed const & src );

    bool operator>( Fixed const & a ) const;
    bool operator<( Fixed const & a ) const;
    bool operator>=( Fixed const & a ) const;
    bool operator<=( Fixed const & a ) const;
    bool operator==( Fixed const & a ) const;
    bool operator!=( Fixed const & a ) const;

    Fixed operator+( Fixed const & a ) const;
    Fixed operator-( Fixed const & a ) const;
    Fixed operator*( Fixed const & a ) const;
    Fixed operator/( Fixed const & a ) const;

    Fixed & operator++();
    Fixed & operator--();
    Fixed operator++( int );
    Fixed operator--( int );

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;

    static Fixed & min( Fixed & lhs, Fixed & rhs );
    static Fixed & max( Fixed & lhs, Fixed & rhs );
    static Fixed const & min( Fixed const & lhs, Fixed const & rhs );
    static Fixed const & max( Fixed const & lhs, Fixed const & rhs );

private:
    int _value;
    static int const _fractional = 8;
};

std::ostream & operator<<( std::ostream & o, const Fixed & src );

#endif

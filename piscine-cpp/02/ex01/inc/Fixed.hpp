/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:52:49 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/02 08:58:35 by mbarberi         ###   ########.fr       */
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

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

private:
    int _value;
    static int const _fractional = 8;
};

std::ostream & operator<<( std::ostream & o, const Fixed & src );

#endif

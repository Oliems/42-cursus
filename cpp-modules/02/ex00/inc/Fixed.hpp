/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:52:49 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/02 08:54:13 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
    Fixed();
    Fixed( const Fixed & src );
    ~Fixed();

    Fixed & operator=( const Fixed & src );

    int getRawBits( void ) const;
    void setRawBits( int const raw );

private:
    int _value;
    static const int _fractional = 8;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:45:38 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/31 12:59:18 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap( T & a, T & b ) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min( T const & a, T const & b ) {
    return a < b ? a : b;
}

template <typename T>
T max( T const & a, T const & b ) {
    return a > b ? a : b;
}

#endif

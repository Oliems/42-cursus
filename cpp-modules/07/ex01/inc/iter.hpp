/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:20:49 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/31 13:31:42 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <stddef.h>

template <typename T>
void iter( T * arr, size_t length, void fn( T & o ) ) {
    for ( size_t i = 0; i < length; i++ )
        fn( arr[ i ] );
}
#endif

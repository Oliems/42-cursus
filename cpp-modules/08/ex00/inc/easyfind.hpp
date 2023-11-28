/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:10:36 by mbarberi          #+#    #+#             */
/*   Updated: 2023/09/05 15:44:15 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
int easyfind( T & cont, int value ) {
    if ( std::find( cont.begin(), cont.end(), value ) == cont.end() )
        return 1;
    return 0;
}

#endif

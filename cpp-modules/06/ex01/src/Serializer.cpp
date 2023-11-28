/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:30:48 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/31 12:14:00 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <stdint.h>

uintptr_t Serializer::serialize( Data * ptr ) {
    return reinterpret_cast<uintptr_t>( ptr );
}

Data * Serializer::deserialize( uintptr_t raw ) {
    return reinterpret_cast<Data *>( raw );
}

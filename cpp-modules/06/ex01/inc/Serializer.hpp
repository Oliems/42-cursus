/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:30:29 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/31 12:15:34 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

struct Data;

class Serializer {
public:
    static uintptr_t serialize( Data * ptr );
    static Data * deserialize( uintptr_t raw );

private:
    Serializer();
};

#endif

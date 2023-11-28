/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:04:06 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/29 12:33:21 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define BRAIN_SIZE 100

class Brain {
public:
    Brain();
    ~Brain();
    Brain( const Brain & o );

    Brain & operator=( const Brain & o );

private:
    std::string _ideas[ BRAIN_SIZE ];
};

#endif

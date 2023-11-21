/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:23:30 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/28 14:47:26 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

#define DEBUG_HASH 210670746764UL
#define INFO_HASH 6384151633UL
#define WARNING_HASH 229444843303835UL
#define ERROR_HASH 210672417103UL

int hash( std::string s );

class Harl {
public:
    Harl();
    ~Harl();
    void complain( std::string level );

private:
    void _debug( void );
    void _info( void );
    void _warning( void );
    void _error( void );
    void ( Harl::*_arrayFunc[ 4 ] )();
};

#endif

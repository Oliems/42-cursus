/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:45:09 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/01 13:45:36 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
public:
    ClapTrap();
    ClapTrap( std::string const & name );
    ClapTrap( ClapTrap const & o );
    ~ClapTrap();

    ClapTrap & operator=( ClapTrap const & o );

    void attack( const std::string & target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );

    int getHp() const;
    int getEp() const;
    int getAd() const;
    std::string getName() const;

private:
    int _hp;
    int _ep;
    int _ad;
    std::string _name;
};

std::ostream & operator<<( std::ostream & o, ClapTrap const & c );

#endif

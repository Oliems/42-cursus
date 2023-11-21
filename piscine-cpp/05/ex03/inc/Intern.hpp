/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:31:11 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/22 19:42:00 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern {
public:
    Intern();
    Intern( Intern const & src );
    ~Intern();

    Intern & operator=( Intern const & src );

    AForm * makeForm( std::string name, std::string target );
};

#endif

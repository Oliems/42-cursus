/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:12:33 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/22 18:52:08 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm( std::string target );
    ShrubberyCreationForm( ShrubberyCreationForm const & o );
    virtual ~ShrubberyCreationForm();

    ShrubberyCreationForm & operator=( ShrubberyCreationForm const & o );

private:
    const std::string _target;

    void beExecuted() const;
};

#endif

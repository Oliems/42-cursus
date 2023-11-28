/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:08:25 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/22 18:52:00 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm();
    PresidentialPardonForm( std::string target );
    PresidentialPardonForm( PresidentialPardonForm const & o );
    virtual ~PresidentialPardonForm();

    PresidentialPardonForm & operator=( PresidentialPardonForm const & o );

private:
    const std::string _target;

    void beExecuted() const;
};

#endif

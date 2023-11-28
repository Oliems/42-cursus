/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:12:03 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/22 18:52:04 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm();
    RobotomyRequestForm( std::string target );
    RobotomyRequestForm( RobotomyRequestForm const & o );
    virtual ~RobotomyRequestForm();

    RobotomyRequestForm & operator=( RobotomyRequestForm const & o );

private:
    const std::string _target;

    void beExecuted() const;
};

#endif

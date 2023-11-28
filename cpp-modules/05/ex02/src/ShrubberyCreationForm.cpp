/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:03:43 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/22 19:26:28 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm( "Shrubbery Creation", 145, 137 )
    , _target( "Default" ) {
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
    : AForm( "Shrubbery Creation", 145, 137 )
    , _target( target ) {
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & o )
    : AForm( "Shrubbery Creation", 145, 137 )
    , _target( o._target + "_copy" ) {
    *this = o;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & o ) {
    ( void )o;
    return *this;
}

void ShrubberyCreationForm::beExecuted() const {
    std::ofstream file;
    std::string filename = this->_target + "_shrubbery";

    file.exceptions( std::ifstream::failbit | std::ifstream::badbit );
    file.open( filename.c_str() );
    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\\\" << std::endl;
    file.close();
}

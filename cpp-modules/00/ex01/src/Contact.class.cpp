/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:34:39 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/26 12:43:56 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact( void ) { }
Contact::~Contact( void ) { }

void Contact::print_info( void ) {
    std::cout << "\tFIRST NAME:\t" << this->_first_name << std::endl;
    std::cout << "\tLAST NAME:\t" << this->_last_name << std::endl;
    std::cout << "\tNICKNAME:\t" << this->_nickname << std::endl;
    std::cout << "\tPHONE:\t\t" << this->_phone_number << std::endl;
    std::cout << "\tDARKEST SECRET:\t" << this->_darkest_secret << std::endl;
}

void Contact::set_info( std::string first_name, std::string last_name,
                        std::string nickname, std::string phone_number, std::string darkest_secret ) {
    this->_first_name = first_name;
    this->_last_name = last_name;
    this->_nickname = nickname;
    this->_phone_number = phone_number;
    this->_darkest_secret = darkest_secret;
}

std::string Contact::get_first_name( void ) {
    if ( this->_first_name.length() > 10 ) {
        std::string firstname;
        firstname = this->_first_name.substr( 0, 9 );
        firstname.push_back( '.' );
        return firstname;
    }
    return this->_first_name;
}

std::string Contact::get_last_name() {
    if ( this->_last_name.length() > 10 ) {
        std::string lastname;
        lastname = this->_last_name.substr( 0, 9 );
        lastname.push_back( '.' );
        return lastname;
    }
    return this->_last_name;
}

std::string Contact::get_nickname() {
    if ( this->_nickname.length() > 10 ) {
        std::string nickname;
        nickname = this->_nickname.substr( 0, 9 );
        nickname.push_back( '.' );
        return nickname;
    }
    return this->_nickname;
}

std::string Contact::get_phone_number( void ) {
    return this->_phone_number;
}

std::string Contact::get_darkest_secret( void ) {
    return this->_darkest_secret;
}

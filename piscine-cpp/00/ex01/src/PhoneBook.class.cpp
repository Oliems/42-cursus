/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:34:44 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/26 12:47:10 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook( void ) {
    this->_size = 0;
    this->_index = 0;
}

PhoneBook::~PhoneBook( void ) { }

void PhoneBook::contact_print( int index ) {
    if ( index >= 0 && index <= 7 && index < this->_size )
        this->_phonebook[ index ].print_info();
    else
        std::cout << "\tERROR: INPUT NOT IN RANGE [0-" << this->_size - 1 << "]\n";
}

void PhoneBook::contact_list( void ) {
    std::cout << "\t---INDEX----FIRST NAME--LAST_NAME--NICKNAME--\n";
    for ( int i = 0; i < this->_size; i++ ) {
        std::cout << "\t|" << std::setw( 10 ) << i;
        std::cout << "|" << std::setw( 10 ) << this->_phonebook[ i ].get_first_name();
        std::cout << "|" << std::setw( 10 ) << this->_phonebook[ i ].get_last_name();
        std::cout << "|" << std::setw( 10 ) << this->_phonebook[ i ].get_nickname();
        std::cout << "|\n";
    }
    std::cout << "\t---------------------------------------------\n";
}

void PhoneBook::contact_add() {
    std::string buf[ 5 ];

    getinput( buf[ 0 ], "\tFIRST NAME: " );
    getinput( buf[ 1 ], "\tLAST NAME: " );
    getinput( buf[ 2 ], "\tNICKNAME: " );
    while ( 1 ) {
        getinput( buf[ 3 ], "\tPHONE: " );
        if ( str_isnum( buf[ 3 ] ) )
            break;
        else
            std::cout << "\tERROR: NON-NUMERIC CHARACTERS IN PHONE NUMBER.\n";
    }
    getinput( buf[ 4 ], "\tDARKEST SECRET: " );

    this->_phonebook[ this->_index ].set_info(
        this->_phonebook[ this->_index ].get_first_name(),
        this->_phonebook[ this->_index ].get_last_name(),
        this->_phonebook[ this->_index ].get_nickname(),
        this->_phonebook[ this->_index ].get_phone_number(),
        this->_phonebook[ this->_index ].get_darkest_secret() );

    this->_phonebook[ this->_index ].set_info( buf[ 0 ], buf[ 1 ], buf[ 2 ], buf[ 3 ], buf[ 4 ] );
    if ( this->_size < MAX_CONTACT )
        this->_size++;
    if ( this->_index < MAX_CONTACT - 1 )
        this->_index++;
    else
        this->_index = 0;
}

int PhoneBook::get_size() {
    return this->_size;
}

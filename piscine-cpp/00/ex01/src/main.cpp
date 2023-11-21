/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:34:41 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/26 11:39:26 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool str_isnum( std::string s ) {
    for ( size_t i = 0; i < s.length(); i++ )
        if ( !isdigit( s[ i ] ) )
            return false;
    return true;
}

void getinput( std::string & s, std::string prompt ) {
    s.clear();
    while ( s.empty() ) {
        std::cout << prompt;
        std::getline( std::cin, s );
        if ( std::cin.eof() ) {
            std::cout << "\n";
            exit( 0 );
        }
    }
}

int main( void ) {
    PhoneBook phonebook;

    std::cout << "WELCOME TO YOUR PHONEBOOK FROM THE 80S! YOU CAN TYPE `ADD' TO ADD A CONTACT, `SEARCH' TO FIND A CONTACT OR `EXIT' TO QUIT THE PROGRAM.\n";
    while ( 1 ) {
        std::string s;
        getinput( s, "> " );
        std::cout << "\n";
        if ( !s.compare( "ADD" ) )
            phonebook.contact_add();
        else if ( !s.compare( "EXIT" ) )
            break;
        else if ( !s.compare( "SEARCH" ) ) {
            if ( phonebook.get_size() > 0 ) {
                std::string index;
                phonebook.contact_list();
                getinput( index, "\tINDEX OF THE CONTACT TO DISPLAY: " );
                std::cout << "\n";
                if ( str_isnum( index ) )
                    phonebook.contact_print( atoi( index.c_str() ) );
                else
                    std::cout << "\tERROR: INPUT NOT IN RANGE [0-7]\n";
                std::cout << "\n";
            } else
                std::cout << "\tNOTHING TO SHOW.\n";
        } else if ( s.length() > 0 )
            std::cout << "USAGE: TYPE `ADD' OR `SEARCH' OR `EXIT'.\n";
    }
    std::cout << "GOODBYE! :-)\n";
    return 0;
}

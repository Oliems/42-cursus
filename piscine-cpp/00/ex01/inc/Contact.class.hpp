/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:32:36 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/26 12:43:56 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <string>

class Contact {
public:
    Contact( void );
    ~Contact( void );

    void print_info( void );
    void set_info( std::string first, std::string last, std::string nick, std::string phone, std::string secret );

    std::string get_first_name( void );
    std::string get_last_name( void );
    std::string get_nickname( void );
    std::string get_phone_number( void );
    std::string get_darkest_secret( void );

private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;
};

#endif

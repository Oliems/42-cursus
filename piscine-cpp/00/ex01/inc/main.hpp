/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:34:32 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/26 12:44:56 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#define MAX_CONTACT 8

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <string>

void getinput( std::string & s, std::string prompt );
bool str_isnum( std::string s );

#endif

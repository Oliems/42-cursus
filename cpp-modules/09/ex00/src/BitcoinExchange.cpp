/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:45:41 by mbarberi          #+#    #+#             */
/*   Updated: 2023/10/30 11:10:59 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

static double GetExchangeRate( std::map<std::string, double> const & data, std::string const & date ) {
    /* look for the key that is not less than date  */
    std::map<std::string, double>::const_iterator it = data.lower_bound( date );
    if ( it != data.end() ) {     /* the key was found, return the corresponding value */
        return it->second;
    } else if ( !data.empty() ) { /* the key was not found and the map is not empty, use the closest date */
        return ( --it )->second;
    }
    return -1.0;
}

static bool ValidateDate( std::string const & date ) {
    std::string::size_type del1 = date.find( '-' );
    std::string::size_type del2 = date.rfind( '-' );

    if ( del1 == std::string::npos || del1 == del2 )
        return false;

    std::string year_str = date.substr( 0, del1 );
    std::string month_str = date.substr( del1 + 1, del2 - del1 - 1 );
    std::string day_str = date.substr( del2 + 1 );

    int year, month, day;
    std::istringstream year_ss( year_str ), month_ss( month_str ), day_ss( day_str );

    /*
     * The >> operator in this context is an extraction operator. It tries to
     * read and convert the string data from the input stream into integers.
     */
    if ( !( year_ss >> year ) || !( month_ss >> month ) || !( day_ss >> day ) )
        return false;
    if ( year < 0 || month < 1 || month > 12 || day < 1 || day > 31 )
        return false;

    /* check for months with only 30 days */
    if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
        if ( day > 30 )
            return false;
    }
    /* a year is a leap year if it is evenly divisible by 4, but
     * century years (those ending in 00) are only leap years if they
     * are evenly divisible by 400.
     */
    if ( month == 2 ) {
        bool isLeapYear = ( !( year % 4 ) && ( ( year % 100 ) || !( year % 400 ) ) );
        if ( ( isLeapYear && day > 29 ) || ( !isLeapYear && day > 28 ) ) {
            return false;
        }
    }
    return true;
}

static void LoadDB( std::map<std::string, double> & data, std::string const & filename ) {
    std::string line;
    std::ifstream file( filename.c_str() );
    std::getline( file, line );
    while ( std::getline( file, line ) ) {
        std::string::size_type delimiter_pos = line.find( ',' );
        if ( delimiter_pos == std::string::npos ) {
            std::cerr << "Error: Invalid format in database => " << line << '\n';
            continue;
        }

        /* Extract the date and rate substrings */
        std::string date = line.substr( 0, delimiter_pos );
        std::string rate_str = line.substr( delimiter_pos + 1 );

        if ( !ValidateDate( date ) ) { /* convert the rate substring to double */
            std::cerr << "Error: Invalid date format in database => " << date << '\n';
            continue;
        }

        double rate;
        std::istringstream rate_stream( rate_str );
        if ( !( rate_stream >> rate ) ) { /* convert the rate substring to double */
            std::cerr << "Error: Invalid rate format in database => " << rate_str << '\n';
            continue;
        }
        data[ date ] = rate;
    }
}

void ProcessInput( std::string const & filename, std::string const & db ) {
    std::map<std::string, double> map;

    LoadDB( map, db );
    std::ifstream file( filename.c_str() );
    std::string line;
    std::getline( file, line );
    while ( std::getline( file, line ) ) {
        std::istringstream ss( line );
        std::string date;
        double value;
        char delimiter;

        if ( !( ss >> date >> delimiter >> value ) ) { /* store each part of the line in the corresponding varible */
            std::cerr << "Error: Unable to parse line => " << line << '\n';
            continue;
        }
        if ( delimiter != '|' ) {
            std::cerr << "Error: Expected '|' delimiter in line => " << line << '\n';
            continue;
        }
        if ( !ValidateDate( date ) ) {
            std::cerr << "Error: Invalid date format in line => " << line << '\n';
            continue;
        }
        if ( value < 0 || value > 1000 ) {
            std::cerr << "Error: Value " << value << " is not a positive number between 0 and 1000.\n";
            continue;
        }
        double exchangeRate = GetExchangeRate( map, date );
        if ( exchangeRate < 0 ) {
            std::cerr << "Error: No exchange rate available for date => " << date << '\n';
            continue;
        }
        std::cout << date << " => " << value << " = " << value * exchangeRate << '\n';
    }
}

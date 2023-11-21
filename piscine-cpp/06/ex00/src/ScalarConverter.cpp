/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:50:37 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/31 12:10:22 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

static void literalHandler( std::string s ) {
    std::cout << "char: impossible\nint: impossible\n";
    if ( s == "nan" || s == "nanf" )
        std::cout << "float: nanf\ndouble: nan\n";
    else
        std::cout << ( ( s == "+inff" || s == "+inf" ) ? "float: +inff\ndouble: +inf\n" : "float: -inff\ndouble: -inf\n" );
}

static int isValidLiteral( std::string s ) {
    if ( isprint( s[ 0 ] ) && s.length() == 1 ) {
        if ( isdigit( s[ 0 ] ) )
            return INTEGER;
        return CHAR;
    }
    size_t i = 0;
    if ( s[ i ] == '+' || s[ i ] == '-' )
        i++;
    int has_dot = 0;
    for ( ; i < s.length(); i++ ) {
        if ( s[ i ] == '.' ) {
            if ( !has_dot )
                has_dot = 1;
            else
                return INVALID;
        }
        if ( !isdigit( s[ i ] ) && s[ i ] != '.' ) {
            if ( ( s[ i ] == 'f' ) && ( i == s.size() - 1 ) )
                return FLOAT;
            else
                return INVALID;
        }
    }
    return has_dot ? DOUBLE : INTEGER;
}

void ScalarConverter::convert( std::string s ) {
    if ( s == "-inff" || s == "+inff" || s == "nanf" || s == "-inf" || s == "+inf" || s == "nan" ) {
        literalHandler( s );
        return;
    }
    double tmp = 0;
    int type = isValidLiteral( s );
    if ( type == INVALID ) {
        std::cout << s << " is not a valid number literal.\n";
        return;
    } else if ( type == CHAR ) {
        tmp = static_cast<double>( s[ 0 ] );
    } else {
        tmp = atof( s.c_str() );
    }
    std::cout << "char: ";
    if ( ( tmp >= 0 && tmp <= 127 ) && isprint( tmp ) )
        std::cout << "'" << static_cast<char>( tmp ) << "'";
    else
        std::cout << "non displayable";
    std::cout << "\nint: ";
    if ( tmp > INT_MAX || tmp < INT_MIN )
        std::cout << "impossible";
    else
        std::cout << static_cast<int>( tmp );
    std::cout << std::fixed;
    std::cout << std::setprecision( 4 );
    std::cout << "\nfloat: " << static_cast<float>( tmp ) << "f";
    std::cout << "\ndouble: " << tmp << "\n";
}

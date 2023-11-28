/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:06:59 by mbarberi          #+#    #+#             */
/*   Updated: 2023/09/16 16:59:52 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>

static void PopTokens( token & a, token & b, std::stack<token> & stack ) {
    b = stack.top();
    stack.pop();
    a = stack.top();
    stack.pop();
}

static token Eval( std::stack<token> & stack, char op ) {
    int a, b;
    PopTokens( a, b, stack );
    switch ( op ) {
    case '+':
        return a + b;
    case '*':
        return a * b;
    case '-':
        return a - b;
    case '/':
        if ( !b )
            throw std::runtime_error( "Division by 0" );
        else
            return a / b;
    }
    return 0;
}

token ResolveExpression( std::string const & s ) {
    std::stack<token> stack;

    if ( s.empty() )
        throw std::runtime_error( "Invalid expression." );
    if ( s.size() == 1 ) {
        if ( std::isdigit( s[ 0 ] ) )
            return static_cast<token>( s[ 0 ] - '0' );
        else
            throw std::runtime_error( "Invalid expression." );
    }
    for ( size_t i = 0; i < s.length(); i++ ) {
        if ( std::isspace( s[ i ] ) ) {
            continue;
        } else if ( std::isdigit( s[ i ] ) ) {
            if ( std::isspace( s[ i + 1 ] ) )
                stack.push( static_cast<token>( s[ i ] - '0' ) );
            else
                throw std::runtime_error( "Not in range [0-9]." );
        } else {
            if ( ( s[ i ] == '+' || s[ i ] == '-' || s[ i ] == '*' || s[ i ] == '/' ) && stack.size() >= 2 )
                stack.push( Eval( stack, s[ i ] ) );
            else
                throw std::runtime_error( "Too few elements on stack." );
        }
    }
    if ( stack.size() > 1 )
        throw std::runtime_error( "No operators left and stack has more than one element." );
    return stack.top();
}

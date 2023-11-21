/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:47:26 by mbarberi          #+#    #+#             */
/*   Updated: 2023/08/31 11:21:22 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

/*
 * C++ does not provide truly static classes unlike other languages like
 * C#.
 *
 * In C#, a static class is defined as follow : A static class is similar
 * to a class that is both abstract and sealed. The difference between a
 * static class and a non-static class is that a static class cannot be
 * instantiated or inherited and that all of the members of the class are
 * static in nature.
 *
 * Since the class cannot be instantiated, it makes no sense to declare a
 * destructor, copy constructor and overload of assigment operator.
 */

enum literalTypes {
    INVALID,
    INTEGER,
    DOUBLE,
    FLOAT,
    CHAR
};

class ScalarConverter {
public:
    static void convert( std::string s );

private:
    ScalarConverter();
};

#endif

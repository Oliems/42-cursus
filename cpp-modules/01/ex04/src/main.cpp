/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:45:14 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/28 13:09:16 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main( int argc, char ** argv ) {
    if ( argc != 4 ) {
        std::cout << "Usage: ./replace <filename> <toreplace> <replacement>\n";
        return 0;
    }

    std::string inFilename = argv[ 1 ], outFilename = inFilename + ".replace", toReplace = argv[ 2 ], replacement = argv[ 3 ];

    std::ifstream infile;
    infile.open( inFilename.c_str() );
    if ( infile.fail() ) {
        std::cerr << "Error: " << inFilename << ": " << strerror( errno ) << "\n";
        return 1;
    }
    std::ofstream outfile;
    outfile.open( outFilename.c_str() );
    if ( outfile.fail() ) {
        std::cerr << "Error: " << outFilename << ": " << strerror( errno ) << "\n";
        return 1;
    }

    std::stringstream infileStream;
    infileStream << infile.rdbuf();
    std::string infileString = infileStream.str();

    if ( toReplace.empty() ) {
        outfile << infileString;
        return 0;
    }
    for ( size_t i = 0; i < infileString.length(); i++ ) {
        if ( infileString.substr( i ).find( toReplace ) == 0 ) {
            outfile << replacement;
            i += toReplace.length() - 1;
        } else {
            outfile << infileString[ i ];
        }
    }
    return 0;
}

#include <iostream>
#include <string>

int main( void ) {
    std::string string = "HI THIS IS BRAIN";
    std::string * stringPTR = &string;
    std::string & stringREF = string;

    std::cout << "string:\t\t" << &string << " | " << string << "\n";
    std::cout << "stringPTR:\t" << stringPTR << " | " << *stringPTR << "\n";
    std::cout << "stringREF:\t" << &stringREF << " | " << stringREF << "\n";
}

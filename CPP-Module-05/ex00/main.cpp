#include "Bureaucrat.hpp"
#include <iostream>
int main() {
    try {
        Bureaucrat b("Alice", 2);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        b.incrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat bad("Bad", 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

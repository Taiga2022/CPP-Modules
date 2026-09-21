#include "Animal.hpp"
#include <iostream>
Animal::Animal(void) : type("Animal") { std::cout << "Animal constructed" << std::endl; }
Animal::Animal(const Animal &other) : type(other.type) { std::cout << "Animal copied" << std::endl; }
Animal &Animal::operator=(const Animal &other)
{ if (this != &other) type = other.type; return (*this); }
Animal::~Animal(void) { std::cout << "Animal destroyed" << std::endl; }
const std::string &Animal::getType(void) const { return (type); }

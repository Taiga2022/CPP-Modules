#include "WrongAnimal.hpp"
#include <iostream>
WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{ std::cout << "WrongAnimal constructed" << std::endl; }
WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{ std::cout << "WrongAnimal copy constructed" << std::endl; }
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{ if (this != &other) type = other.type; return (*this); }
WrongAnimal::~WrongAnimal(void)
{ std::cout << "WrongAnimal destroyed" << std::endl; }
const std::string &WrongAnimal::getType(void) const { return (type); }
void WrongAnimal::makeSound(void) const
{ std::cout << "The wrong animal makes a sound" << std::endl; }

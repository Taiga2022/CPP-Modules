#include "Cat.hpp"
#include <iostream>
Cat::Cat(void) : Animal() { type = "Cat"; std::cout << "Cat constructed" << std::endl; }
Cat::Cat(const Cat &other) : Animal(other)
{ std::cout << "Cat copy constructed" << std::endl; }
Cat &Cat::operator=(const Cat &other)
{ Animal::operator=(other); return (*this); }
Cat::~Cat(void) { std::cout << "Cat destroyed" << std::endl; }
void Cat::makeSound(void) const { std::cout << "Meow!" << std::endl; }

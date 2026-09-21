#include "WrongCat.hpp"
#include <iostream>
WrongCat::WrongCat(void) : WrongAnimal()
{ type = "WrongCat"; std::cout << "WrongCat constructed" << std::endl; }
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{ std::cout << "WrongCat copy constructed" << std::endl; }
WrongCat &WrongCat::operator=(const WrongCat &other)
{ WrongAnimal::operator=(other); return (*this); }
WrongCat::~WrongCat(void) { std::cout << "WrongCat destroyed" << std::endl; }
void WrongCat::makeSound(void) const { std::cout << "Wrong meow!" << std::endl; }

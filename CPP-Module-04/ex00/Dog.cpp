#include "Dog.hpp"
#include <iostream>
Dog::Dog(void) : Animal()
{
	type = "Dog";
	std::cout << "Dog constructed" << std::endl;
}
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructed" << std::endl;
}
Dog &Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	return (*this);
}
Dog::~Dog(void) { std::cout << "Dog destroyed" << std::endl; }
void Dog::makeSound(void) const { std::cout << "Woof!" << std::endl; }

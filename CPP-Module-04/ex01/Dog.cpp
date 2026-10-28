#include "Dog.hpp"
#include <iostream>
Dog::Dog(void) : Animal(), _brain(new Brain())
{
	type = "Dog";
	std::cout << "Dog constructed" << std::endl;
}
Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Dog copied" << std::endl;
}
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	return (*this);
}
Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destroyed" << std::endl;
}
void Dog::makeSound(void) const { std::cout << "Woof!" << std::endl; }
Brain &Dog::getBrain(void) { return (*_brain); }
const Brain &Dog::getBrain(void) const { return (*_brain); }

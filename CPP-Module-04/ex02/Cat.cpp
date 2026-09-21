#include "Cat.hpp"
#include <iostream>
Cat::Cat(void) : Animal(), _brain(new Brain()) { type = "Cat"; std::cout << "Cat constructed" << std::endl; }
Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain)) { std::cout << "Cat copied" << std::endl; }
Cat &Cat::operator=(const Cat &other)
{ if (this != &other) { Animal::operator=(other); *_brain = *other._brain; } return (*this); }
Cat::~Cat(void) { delete _brain; std::cout << "Cat destroyed" << std::endl; }
void Cat::makeSound(void) const { std::cout << "Meow!" << std::endl; }
Brain &Cat::getBrain(void) { return (*_brain); }

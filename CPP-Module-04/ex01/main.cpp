#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
int main(void)
{
	Animal *animals[4];
	for (int i = 0; i < 2; ++i)
		animals[i] = new Dog();
	for (int i = 2; i < 4; ++i)
		animals[i] = new Cat();
	for (int i = 0; i < 4; ++i)
	{
		animals[i]->makeSound();
		delete animals[i];
	}
	Dog original;
	original.getBrain().setIdea(0, "chase the ball");
	Dog copy(original);
	original.getBrain().setIdea(0, "take a nap");
	std::cout << "copied idea: " << copy.getBrain().getIdea(0) << std::endl;
	return (0);
}

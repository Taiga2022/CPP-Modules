#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
int main(void)
{
	Animal *animals[2];
	animals[0] = new Dog();
	animals[1] = new Cat();
	for (int i = 0; i < 2; ++i) { animals[i]->makeSound(); delete animals[i]; }
	return (0);
}

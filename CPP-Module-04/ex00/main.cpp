#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
int main(void)
{
	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	dog->makeSound();
	cat->makeSound();
	animal->makeSound();
	delete dog;
	delete cat;
	delete animal;
	const WrongCat wrongCat;
	const WrongAnimal *wrong = &wrongCat;
	wrong->makeSound();
	return (0);
}

#include "Zombie.hpp"

int main(void)
{
	Zombie *heapZombie = newZombie("Heap zombie");

	heapZombie->announce();
	delete heapZombie;
	randomChump("Stack zombie");
	return (0);
}

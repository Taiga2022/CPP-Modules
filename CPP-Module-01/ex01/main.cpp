#include "Zombie.hpp"

int main(void)
{
	const int size = 5;
	Zombie *horde = zombieHorde(size, "Horde zombie");

	if (horde == NULL)
		return (1);
	for (int i = 0; i < size; ++i)
		horde[i].announce();
	delete [] horde;
	return (0);
}

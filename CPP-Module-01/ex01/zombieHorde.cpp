#include "Zombie.hpp"
#include <new>

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *horde;

	if (N <= 0)
		return (NULL);
	horde = new (std::nothrow) Zombie[N];
	if (horde == NULL)
		return (NULL);
	for (int i = 0; i < N; ++i)
		horde[i].setName(name);
	return (horde);
}

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap unit("CL4P-TP");

	unit.attack("target");
	unit.takeDamage(4);
	unit.beRepaired(2);
	unit.takeDamage(20);
	unit.attack("target");
	unit.beRepaired(5);
	return (0);
}

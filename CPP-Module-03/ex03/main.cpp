#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamond("DI4M-TP");

	diamond.whoAmI();
	diamond.attack("target");
	diamond.takeDamage(40);
	diamond.beRepaired(10);
	diamond.guardGate();
	diamond.highFivesGuys();
	DiamondTrap copy(diamond);
	copy.whoAmI();
	return (0);
}

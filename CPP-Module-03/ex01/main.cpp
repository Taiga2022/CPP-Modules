#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap("Clappy");
	ScavTrap scav("SC4V-TP");

	clap.attack("target");
	scav.attack("target");
	scav.guardGate();
	scav.takeDamage(30);
	scav.beRepaired(10);
	return (0);
}

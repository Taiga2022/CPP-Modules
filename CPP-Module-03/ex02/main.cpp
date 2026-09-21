#include "FragTrap.hpp"
#include "ScavTrap.hpp"
int main(void)
{
	ScavTrap scav("SC4V-TP");
	FragTrap frag("FR4G-TP");
	scav.attack("target");
	scav.guardGate();
	frag.attack("target");
	frag.highFivesGuys();
	frag.takeDamage(40);
	frag.beRepaired(10);
	return (0);
}

#include "FragTrap.hpp"
#include <iostream>
FragTrap::FragTrap(void) : ClapTrap("FragTrap")
{
	_hitPoints = 100; _energyPoints = 100; _attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100; _energyPoints = 100; _attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructed" << std::endl;
}
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{ std::cout << "FragTrap copy constructor called" << std::endl; }
FragTrap &FragTrap::operator=(const FragTrap &other)
{ ClapTrap::operator=(other); return (*this); }
FragTrap::~FragTrap(void)
{ std::cout << "FragTrap " << _name << " destroyed" << std::endl; }
void FragTrap::highFivesGuys(void)
{ std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl; }

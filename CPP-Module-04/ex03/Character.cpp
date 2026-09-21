#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void) : _name("Character")
{ for (int i = 0; i < 4; ++i) _inventory[i] = NULL; }
Character::Character(const std::string &name) : _name(name)
{ for (int i = 0; i < 4; ++i) _inventory[i] = NULL; }
Character::Character(const Character &other) : _name(other._name)
{
	for (int i = 0; i < 4; ++i) _inventory[i] = NULL;
	try
	{
		for (int i = 0; i < 4; ++i)
			if (other._inventory[i] != NULL)
				_inventory[i] = other._inventory[i]->clone();
	}
	catch (...) { clearInventory(); throw; }
}
Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		AMateria *copies[4] = {NULL, NULL, NULL, NULL};
		try
		{
			for (int i = 0; i < 4; ++i)
				if (other._inventory[i] != NULL)
					copies[i] = other._inventory[i]->clone();
		}
		catch (...)
		{
			for (int i = 0; i < 4; ++i) delete copies[i];
			throw;
		}
		clearInventory();
		_name = other._name;
		for (int i = 0; i < 4; ++i) _inventory[i] = copies[i];
	}
	return (*this);
}
Character::~Character(void) { clearInventory(); }
void Character::clearInventory(void)
{ for (int i = 0; i < 4; ++i) { delete _inventory[i]; _inventory[i] = NULL; } }
const std::string &Character::getName(void) const { return (_name); }
void Character::equip(AMateria *materia)
{
	if (materia == NULL) return ;
	for (int i = 0; i < 4; ++i) if (_inventory[i] == materia) return ;
	for (int i = 0; i < 4; ++i)
		if (_inventory[i] == NULL) { _inventory[i] = materia; return ; }
}
void Character::unequip(int index)
{ if (index >= 0 && index < 4) _inventory[index] = NULL; }
void Character::use(int index, ICharacter &target)
{ if (index >= 0 && index < 4 && _inventory[index] != NULL) _inventory[index]->use(target); }

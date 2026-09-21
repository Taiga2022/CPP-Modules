#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>
int main(void)
{
	IMateriaSource *source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *ice = source->createMateria("ice");
	AMateria *cure = source->createMateria("cure");
	me->equip(ice);
	me->equip(cure);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	AMateria *dropped = source->createMateria("ice");
	me->equip(dropped);
	me->unequip(2);
	delete dropped;
	Character original("original");
	original.equip(source->createMateria("cure"));
	Character copy(original);
	copy.use(0, *bob);
	delete bob;
	delete me;
	delete source;
	return (0);
}

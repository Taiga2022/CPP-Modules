#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
class Character : public ICharacter
{
public:
	Character(void);
	Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	virtual ~Character(void);
	virtual const std::string &getName(void) const;
	virtual void equip(AMateria *materia);
	virtual void unequip(int index);
	virtual void use(int index, ICharacter &target);
private:
	std::string _name;
	AMateria *_inventory[4];
	void clearInventory(void);
};
#endif

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include <string>
class AMateria;
class ICharacter
{
public:
	virtual ~ICharacter(void) {}
	virtual std::string const &getName(void) const = 0;
	virtual void equip(AMateria *materia) = 0;
	virtual void unequip(int index) = 0;
	virtual void use(int index, ICharacter &target) = 0;
};
#endif

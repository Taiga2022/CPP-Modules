#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	virtual ~MateriaSource(void);
	virtual void learnMateria(AMateria *materia);
	virtual AMateria *createMateria(const std::string &type);
private:
	AMateria *_prototypes[4];
	void clearPrototypes(void);
};
#endif

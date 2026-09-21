#include "MateriaSource.hpp"
#include "AMateria.hpp"
MateriaSource::MateriaSource(void)
{ for (int i = 0; i < 4; ++i) _prototypes[i] = NULL; }
MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; ++i) _prototypes[i] = NULL;
	try
	{
		for (int i = 0; i < 4; ++i)
			if (other._prototypes[i] != NULL)
				_prototypes[i] = other._prototypes[i]->clone();
	}
	catch (...) { clearPrototypes(); throw; }
}
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		AMateria *copies[4] = {NULL, NULL, NULL, NULL};
		try
		{
			for (int i = 0; i < 4; ++i)
				if (other._prototypes[i] != NULL)
					copies[i] = other._prototypes[i]->clone();
		}
		catch (...)
		{
			for (int i = 0; i < 4; ++i) delete copies[i];
			throw;
		}
		clearPrototypes();
		for (int i = 0; i < 4; ++i) _prototypes[i] = copies[i];
	}
	return (*this);
}
MateriaSource::~MateriaSource(void) { clearPrototypes(); }
void MateriaSource::clearPrototypes(void)
{ for (int i = 0; i < 4; ++i) { delete _prototypes[i]; _prototypes[i] = NULL; } }
void MateriaSource::learnMateria(AMateria *materia)
{
	if (materia == NULL) return ;
	for (int i = 0; i < 4; ++i) if (_prototypes[i] == materia) return ;
	for (int i = 0; i < 4; ++i)
		if (_prototypes[i] == NULL) { _prototypes[i] = materia; return ; }
}
AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; ++i)
		if (_prototypes[i] != NULL && _prototypes[i]->getType() == type)
			return (_prototypes[i]->clone());
	return (NULL);
}

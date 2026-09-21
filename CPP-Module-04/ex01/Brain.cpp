#include "Brain.hpp"
#include <iostream>
Brain::Brain(void) { std::cout << "Brain constructed" << std::endl; }
Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; ++i) _ideas[i] = other._ideas[i];
	std::cout << "Brain copied" << std::endl;
}
Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
		for (int i = 0; i < 100; ++i) _ideas[i] = other._ideas[i];
	return (*this);
}
Brain::~Brain(void) { std::cout << "Brain destroyed" << std::endl; }
void Brain::setIdea(unsigned int index, const std::string &idea)
{ if (index < 100) _ideas[index] = idea; }
const std::string &Brain::getIdea(unsigned int index) const
{
	static const std::string empty;
	return (index < 100 ? _ideas[index] : empty);
}

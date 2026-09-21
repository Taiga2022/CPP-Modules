#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
class Brain
{
public:
	Brain(void);
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain(void);
	void setIdea(unsigned int index, const std::string &idea);
	const std::string &getIdea(unsigned int index) const;
private:
	std::string _ideas[100];
};
#endif

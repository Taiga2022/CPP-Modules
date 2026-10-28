#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>
class WrongAnimal
{
  public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);
	~WrongAnimal(void);
	const std::string &getType(void) const;
	void makeSound(void) const;

  protected:
	std::string type;
};
#endif

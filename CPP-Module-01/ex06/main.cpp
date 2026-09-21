#include "Harl.hpp"
#include <iostream>
#include <string>

static int levelIndex(const std::string &level)
{
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; ++i)
		if (level == levels[i])
			return (i);
	return (-1);
}

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0]
			<< " <DEBUG|INFO|WARNING|ERROR>" << std::endl;
		return (1);
	}
	switch (levelIndex(argv[1]))
	{
	case 0:
		harl.complain("DEBUG");
	case 1:
		harl.complain("INFO");
	case 2:
		harl.complain("WARNING");
	case 3:
		harl.complain("ERROR");
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
	}
	return (0);
}

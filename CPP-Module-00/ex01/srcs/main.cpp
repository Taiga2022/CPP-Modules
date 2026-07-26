#include "PhoneBook.hpp"

#include <iostream>
#include <string>

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, or EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
		{
			if (!phoneBook.addContact())
			{
				if (std::cin.eof())
					break;
				std::cout << "Contact was not added." << std::endl;
			}
		}
		else if (command == "SEARCH")
		{
			if (!phoneBook.searchContacts() && std::cin.eof())
				break;
		}
		else if (command == "EXIT")
			break;
	}
	return (0);
}

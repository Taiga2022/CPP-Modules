#include "PhoneBook.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace
{
	bool readField(const char *prompt, std::string &field)
	{
		std::cout << prompt;
		return (static_cast<bool>(std::getline(std::cin, field)));
	}

	std::string tableField(const std::string &value)
	{
		if (value.length() > 10)
			return (value.substr(0, 9) + ".");
		return (value);
	}

	bool parseIndex(const std::string &input, int &index)
	{
		std::istringstream stream(input);
		char extra;

		if (!(stream >> index))
			return (false);
		if (stream >> extra)
			return (false);
		return (true);
	}
}

PhoneBook::PhoneBook() : _count(0), _nextIndex(0)
{
}

bool PhoneBook::addContact()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	if (!readField("First name: ", firstName)
		|| !readField("Last name: ", lastName)
		|| !readField("Nickname: ", nickname)
		|| !readField("Phone number: ", phoneNumber)
		|| !readField("Darkest secret: ", darkestSecret))
		return (false);
	if (firstName.empty() || lastName.empty() || nickname.empty()
		|| phoneNumber.empty() || darkestSecret.empty())
		return (false);
	_contacts[_nextIndex].setFields(firstName, lastName, nickname,
		phoneNumber, darkestSecret);
	_nextIndex = (_nextIndex + 1) % 8;
	if (_count < 8)
		++_count;
	return (true);
}

bool PhoneBook::searchContacts() const
{
	std::string input;
	int index;

	for (int i = 0; i < _count; ++i)
	{
		std::cout << std::setw(10) << i << '|'
			<< std::setw(10) << tableField(_contacts[i].getFirstName()) << '|'
			<< std::setw(10) << tableField(_contacts[i].getLastName()) << '|'
			<< std::setw(10) << tableField(_contacts[i].getNickname())
			<< std::endl;
	}
	std::cout << "Index: ";
	if (!std::getline(std::cin, input))
		return (false);
	if (!parseIndex(input, index) || index < 0 || index >= _count)
	{
		std::cout << "Invalid index." << std::endl;
		return (true);
	}
	_contacts[index].displayDetails();
	return (true);
}

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	bool addContact();
	bool searchContacts() const;

private:
	Contact _contacts[8];
	int _count;
	int _nextIndex;
};

#endif

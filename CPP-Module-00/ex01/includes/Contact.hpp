#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
public:
	Contact();
	void setFields(const std::string &firstName, const std::string &lastName,
		const std::string &nickname, const std::string &phoneNumber,
		const std::string &darkestSecret);
	const std::string &getFirstName() const;
	const std::string &getLastName() const;
	const std::string &getNickname() const;
	void displayDetails() const;

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif

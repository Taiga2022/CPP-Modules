#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
Intern::Intern() {}
Intern::Intern(const Intern &) {}
Intern &Intern::operator=(const Intern &) { return *this; }
Intern::~Intern() {}
AForm *Intern::makeShrubbery(const std::string &t) const { return new ShrubberyCreationForm(t); }
AForm *Intern::makeRobotomy(const std::string &t) const { return new RobotomyRequestForm(t); }
AForm *Intern::makePardon(const std::string &t) const { return new PresidentialPardonForm(t); }
AForm *Intern::makeForm(const std::string &n, const std::string &t) const {
    const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    Maker makers[3] = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePardon};
    for (int i = 0; i < 3; ++i)
        if (n == names[i]) {
            std::cout << "Intern creates " << n << std::endl;
            return (this->*makers[i])(t);
        }
    std::cout << "Intern cannot create unknown form: " << n << std::endl;
    return 0;
}

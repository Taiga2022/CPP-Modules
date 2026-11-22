#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Bureaucrat chief("Chief", 1);
    Bureaucrat clerk("Clerk", 150);
    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur");

    clerk.executeForm(shrub);
    clerk.signForm(shrub);
    chief.signForm(shrub);
    clerk.executeForm(shrub);
    chief.executeForm(shrub);
    chief.signForm(robot);
    chief.executeForm(robot);
    chief.signForm(pardon);
    chief.executeForm(pardon);
    return 0;
}

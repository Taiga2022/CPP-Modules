#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    Bureaucrat chief("Chief", 1);
    Bureaucrat clerk("Clerk", 150);
    Intern intern;
    AForm *form = intern.makeForm("robotomy request", "Bender");

    if (form != 0) {
        clerk.executeForm(*form); // unsigned form
        chief.signForm(*form);
        clerk.executeForm(*form); // insufficient execution grade
        chief.executeForm(*form);
        delete form;
    }
    form = intern.makeForm("unknown form", "target");
    delete form;
    return 0;
}

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &t)
    : AForm("robotomy request", 72, 45), _target(t) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &o)
    : AForm(o), _target(o._target) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &o) {
    if (this != &o) {
        AForm::operator=(o);
        _target = o._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::executeAction() const {
    std::cout << "Bzzzzzz... ";
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully.";
    else
        std::cout << "robotomy failed for " << _target << ".";
    std::cout << std::endl;
}

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &t)
    : AForm("shrubbery creation", 145, 137), _target(t) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &o)
    : AForm(o), _target(o._target) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &o) {
    if (this != &o) {
        AForm::operator=(o);
        _target = o._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream file((_target + "_shrubbery").c_str());

    if (!file.is_open())
        throw std::runtime_error("Failed to open file");

    file << "   /\\\n"
         << "  /**\\\n"
         << " /****\\\n"
         << "   ||\n";

    if (!file)
        throw std::runtime_error("Failed to write file");

    file.close();

    if (!file)
        throw std::runtime_error("Failed to close file");
}

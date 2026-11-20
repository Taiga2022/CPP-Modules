#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat() : _name("anonymous"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string &n, int g) : _name(n), _grade(g) {
    if (g < 1)
        throw GradeTooHighException();
    if (g > 150)
        throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &o) : _name(o._name), _grade(o._grade) {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &o) {
    if (this != &o)
        _grade = o._grade;
    return *this;
}
Bureaucrat::~Bureaucrat() {}
const std::string &Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }
void Bureaucrat::incrementGrade() {
    if (_grade == 1)
        throw GradeTooHighException();
    --_grade;
}
void Bureaucrat::decrementGrade() {
    if (_grade == 150)
        throw GradeTooLowException();
    ++_grade;
}
const char *Bureaucrat::GradeTooHighException::what() const throw() { return "grade too high"; }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return "grade too low"; }
std::ostream &operator<<(std::ostream &o, const Bureaucrat &b) {
    return o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}

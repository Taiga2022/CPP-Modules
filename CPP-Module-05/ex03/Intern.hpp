#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
class AForm;
class Intern {
  private:
    typedef AForm *(Intern::*Maker)(const std::string &) const;
    AForm *makeShrubbery(const std::string &) const;
    AForm *makeRobotomy(const std::string &) const;
    AForm *makePardon(const std::string &) const;

  public:
    Intern();
    Intern(const Intern &);
    Intern &operator=(const Intern &);
    ~Intern();
    AForm *makeForm(const std::string &, const std::string &) const;
};
#endif

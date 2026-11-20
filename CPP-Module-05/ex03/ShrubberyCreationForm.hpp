#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
  private:
    std::string _target;

  protected:
    virtual void executeAction() const;

  public:
    ShrubberyCreationForm(const std::string &);
    ShrubberyCreationForm(const ShrubberyCreationForm &);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
    virtual ~ShrubberyCreationForm();
};
#endif

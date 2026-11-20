#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
class PresidentialPardonForm : public AForm {
  private:
    std::string _target;

  protected:
    virtual void executeAction() const;

  public:
    PresidentialPardonForm(const std::string &);
    PresidentialPardonForm(const PresidentialPardonForm &);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &);
    virtual ~PresidentialPardonForm();
};
#endif

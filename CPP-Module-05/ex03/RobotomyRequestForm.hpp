#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  private:
    std::string _target;

  protected:
    virtual void executeAction() const;

  public:
    RobotomyRequestForm(const std::string &);
    RobotomyRequestForm(const RobotomyRequestForm &);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &);
    virtual ~RobotomyRequestForm();
};
#endif

#include "Bureaucrat.hpp"
#include "Form.hpp"
int main() {
    Bureaucrat low("Low", 150);
    Bureaucrat high("High", 1);
    Form form("Top secret", 10, 5);
    low.signForm(form);
    high.signForm(form);
    return 0;
}

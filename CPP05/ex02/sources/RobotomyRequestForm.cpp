#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
AForm("RobotomyRequestForm", 145, 137), target("NoTarget") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const newTarget):
AForm("RobotomyRequestForm", 145, 137), target(newTarget) {
	std::cout << "RobotomyRequestForm constructor with parameters called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& that):
AForm("RobotomyRequestForm", 145, 137), target("NoTarget"){
	*this = that;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;

}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& that){
	if (this != &that) {
		AForm::operator=(that);
		const_cast<std::string&>(target) = that.target;
	}
	return (*this);
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getSing())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToEx())
		throw GradeTooLowException();
	std::cout << CYAN "** drilling noises... **" RESET << std::endl;
	srand(time(0));
	if (rand() % 2)
		std::cout << CYAN << this->target << " has been robotomized successfully!" << RESET << std::endl;
	else
		std::cout << YELLOW << this->target << " robotomy failed!" << RESET << std::endl;
}

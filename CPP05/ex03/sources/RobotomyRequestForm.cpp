#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
AForm("RobotomyRequestForm", 72, 45), target("NoTarget") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const newTarget):
AForm("RobotomyRequestForm", 72, 45), target(newTarget) {
	std::cout << "RobotomyRequestForm constructor with parameters called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& that):
AForm("RobotomyRequestForm", 72, 45), target("NoTarget"){
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
		throw AForm::AFormNotSignedException();
	if (executor.getGrade() > getGradeToEx())
		throw GradeTooLowException();
	std::cout << "** drilling noises... **" << std::endl;
	srand(time(0));
	if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << this->target << " robotomy failed!"<< std::endl;
}

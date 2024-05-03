#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
AForm("PresidentialPardonForm", 145, 137), target("NoTarget") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const newTarget):
AForm("PresidentialPardonForm", 145, 137), target(newTarget) {
	std::cout << "PresidentialPardonForm constructor with parameters called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& that):
AForm("PresidentialPardonForm", 145, 137), target("NoTarget"){
	*this = that;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;

}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& that){
	if (this != &that) {
		AForm::operator=(that);
		const_cast<std::string&>(target) = that.target;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const{
	if (!getSing())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToEx())
		throw GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}

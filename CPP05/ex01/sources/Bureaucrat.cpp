#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Unknown"), grade(1) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(Bureaucrat const &that){
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = that;
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : name(newName), grade(newGrade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat constructor with parameters called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &that){
	std::cout << "Bureaucrat copy assignment operator called." << RESET << std::endl;
	if (this != &that){
		const_cast<std::string&>(name) = that.getName();
		this->grade = that.getGrade();
	}
	return(*this);
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string	Bureaucrat::getName(void) const{
	return(this->name);
}

int	Bureaucrat::getGrade(void) const{
	return(this->grade);
}


void	Bureaucrat::increment(void){
	if (grade == 1)
		throw GradeTooHighException();
	else 
		grade--;
}

void	Bureaucrat::decrement(void){
	if (grade == 150)
		throw GradeTooLowException();
	else 
		grade++;
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Bureaucrat too low, minimum grade is 150");
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Bureaucrat too high, maximum grade is 1");
}

std::ostream &operator<<(std::ostream &os,Bureaucrat const &that){
	os  << CYAN << "Name: " << WHITE << that.getName() << CYAN << "- Bureaucrat grade: " << WHITE << that.getGrade() << RESET;
	return (os);
}

void	Bureaucrat::signForm(Form& form){
	try {
		form.beSigned(*this);
		std::cout << CYAN << this->name << WHITE << " signed " << form.getName() << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << CYAN << this->name << WHITE << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}
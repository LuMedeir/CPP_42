# include "../includes/Form.hpp"

Form::Form(void) : name("Unknown"), sing(false), gradeToEx(100), gradeToSign(100){
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string newName, int newGradeSign, int newGradeEx)
: name(newName), gradeToEx(newGradeEx), gradeToSign(newGradeSign){
	std::cout << "Form constructor with parameters called" << std::endl;
	if (gradeToSign < 1 || gradeToEx < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToEx > 150)
		throw GradeTooLowException();
}


Form::Form(Form const &that) : name("Unknown"), sing(false), gradeToEx(100), gradeToSign(100){
	std::cout << "Form copy constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToEx < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToEx > 150)
		throw GradeTooLowException();
	*this = that;
}

Form::~Form(void){
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &that){
	std::cout << "Form copy assignment operator called." << RESET << std::endl;
	if (this != &that){
		const_cast<std::string&>(this->name) = that.getName();
		this->sing = that.getSing();
		const_cast<int&>(this->gradeToSign) = that.getGradeToSign();
		const_cast<int&>(this->gradeToEx) = that.getGradeToEx();
	}
	return (*this);
}

int	Form::getGradeToSign(void) const{
	return(gradeToSign);
}

int	Form::getGradeToEx(void) const{
	return(gradeToEx);
}

std::string	Form::getName(void) const{
	return(name);
}

bool	Form::getSing(void) const{
	return(sing);
}

const char* Form::GradeTooHighException::what() const throw(){
	return ("Grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw(){
	return ("Grade is too low.");
}

std::ostream& operator<<(std::ostream &os, Form const &that){
	os << CYAN << "Name: " << that.getName() << " - Form signed: " 
		<< std::boolalpha << that.getSing() << " - Form grade to sign: "
		<< that.getGradeToSign() << " - Form grade to execute: "
		<< that.getGradeToEx() << RESET << std::endl;
	return (os);
}

void	Form::beSigned(Bureaucrat const &that){
		if (that.getGrade() > gradeToSign) {
		throw GradeTooLowException();
	}
	sing = true;
}

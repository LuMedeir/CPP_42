# include "../includes/AForm.hpp"

AForm::AForm(void) : name("Unknown"), sing(false), gradeToEx(100), gradeToSign(100){
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string newName, int newGradeSign, int newGradeEx)
: name(newName), gradeToEx(newGradeEx), gradeToSign(newGradeSign){
	sing = false;
	std::cout << "AForm constructor with parameters called" << std::endl;
	if (gradeToSign < 1 || gradeToEx < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToEx > 150)
		throw GradeTooLowException();
}


AForm::AForm(AForm const &that) : name("Unknown"), sing(false), gradeToEx(100), gradeToSign(100){
	std::cout << "AForm copy constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToEx < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToEx > 150)
		throw GradeTooLowException();
	*this = that;
}

AForm::~AForm(void){
	std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &that){
	std::cout << "AForm copy assignment operator called." << RESET << std::endl;
	if (this != &that){
		const_cast<std::string&>(this->name) = that.getName();
		this->sing = that.getSing();
		const_cast<int&>(this->gradeToSign) = that.getGradeToSign();
		const_cast<int&>(this->gradeToEx) = that.getGradeToEx();
	}
	return (*this);
}

int	AForm::getGradeToSign(void) const{
	return(gradeToSign);
}

int	AForm::getGradeToEx(void) const{
	return(gradeToEx);
}

std::string	AForm::getName(void) const{
	return(name);
}

bool	AForm::getSing(void) const{
	return(sing);
}

const char* AForm::GradeTooHighException::what() const throw(){
	return ("Grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw(){
	return ("Grade is too low.");
}

const char* AForm::AFormNotSignedException::what() const throw(){
	return ("AForm isn't signed!");
}

std::ostream& operator<<(std::ostream &os, AForm const &that){
	os << CYAN << "Name: " << WHITE << that.getName() << CYAN << " - Form signed: " 
		<< WHITE << std::boolalpha << that.getSing() << CYAN << " - Form grade to sign: "
		<< WHITE << that.getGradeToSign() << CYAN << " - Form grade to execute: "
		<< WHITE << that.getGradeToEx() << RESET << std::endl;
	return (os);
}

void	AForm::beSigned(Bureaucrat const &that){
		if (that.getGrade() > gradeToSign) {
		throw GradeTooLowException();
	}
	sing = true;
}

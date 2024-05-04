#include "../includes/Intern.hpp"

Intern::Intern(){
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &copy){
	*this = copy;
	std::cout << "Intern destructor called" << std::endl;
}

Intern::~Intern(){
	std::cout << "An Intern has been destroyed!"  << std::endl;
}

Intern &Intern::operator=(Intern const &op){
	std::cout << "Intern copy assignment operator called"  << std::endl;
	(void)op;
	return (*this);
}

AForm *Intern::makeAForm(std::string name, std::string target)
{
	AForm *AForm;
	int i = 0;
	std::string names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	while (i < 3)
	{
		if (name == names[i])
			break;
		i++;
	}

	switch (i)
	{
	case 0:
		AForm = new RobotomyRequestForm(target);
		break;
	case 1:
		AForm = new PresidentialPardonForm(target);
		break;
	case 2:
		AForm = new ShrubberyCreationForm(target);
		break;
	default:
		std::cout << WHITE << "AForm doesn't exist!" << RESET << std::endl;
		return (NULL);
	}

	return AForm;
}
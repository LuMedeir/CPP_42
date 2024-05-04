#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"


int main(void)
{
	std::cout << PURPLE << std::endl;
	std::cout << "---------------------- INTERN TEST ------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------\n" << std::endl;
	std::cout << "-----------------ShrubberyCreationAForm Test--------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET<< std::endl;
	try
	{
		
		Bureaucrat bureaucrat("Lucas", 137);
		std::cout << bureaucrat;
		Intern intern;
		AForm *form;
		form = intern.makeAForm("shrubbery creation", "Amazon");
		std::cout << *form;
		bureaucrat.signAForm(*form);
		std::cout << *form;
		bureaucrat.executeAForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << PURPLE << "---------------------------------------------------------------" << std::endl;
	std::cout << "------------------PresidentialPardonAForm Test------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Leila", 2);
		std::cout << bureaucrat << std::endl;
		Intern intern;
		AForm *form;
		form = intern.makeAForm("presidential pardon", "Billy");
		std::cout << *form  << std::endl;
		bureaucrat.signAForm(*form);
		std::cout << *form << std::endl;
		bureaucrat.executeAForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		
	}
	std::cout << PURPLE << "---------------------------------------------------------------" << std::endl;
	std::cout << "--------------------RobotomyRequestAForm Test-------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Thais", 40);
		std::cout << bureaucrat << std::endl;
		Intern intern;
		AForm *form;
		form = intern.makeAForm("robotomy request", "Bender");
		std::cout << *form << std::endl;
		bureaucrat.signAForm(*form);
		std::cout << *form << std::endl;
		bureaucrat.executeAForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << PURPLE << "---------------------------------------------------------------" << std::endl;
	std::cout << "------------------------Exception Test-------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	try
	{
		Intern intern;
		AForm *form;
		form = intern.makeAForm("default", "default");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

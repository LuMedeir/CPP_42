#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"


int main(void)
{
   std::cout << PURPLE << std::endl;
	std::cout << "------------------------- FORM TEST ---------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "------------------ShrubberyCreationForm Test-------------------\n" << RESET << std::endl;
	try
	{
		Bureaucrat bureaucrat("Lucas", 138);
		ShrubberyCreationForm form("home");
		std::cout << bureaucrat << std::endl;
		std::cout << form;
		std::cout << WHITE << "\nBureaucrat try execute but doesn't has grade enough" << RESET << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form); 
		std::cout << WHITE << "\nBureaucrat increment your grade and now has grade enough" << RESET << std::endl;
		bureaucrat.increment();
		std::cout << bureaucrat << std::endl;
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << PURPLE << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------- PresidentialPardonForm Test -----------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;
	try
	{
		Bureaucrat bureaucrat("Leila", 25);
		PresidentialPardonForm form("Billy");
		std::cout << bureaucrat << std::endl;
		std::cout << form;
		std::cout << WHITE << "\nBureaucrat try execute but doesn't has grade enough" << RESET << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		std::cout << WHITE << "\nBureaucrat increment your grade and now has grade enough" << RESET << std::endl;
		for (int i = 0; i < 20; i++)
			bureaucrat.increment();
		std::cout << bureaucrat << std::endl;
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << PURPLE << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "------------------ RobotomyRequestForm Test -------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;
	try
	{
		Bureaucrat bureaucrat("Thais", 72);
		RobotomyRequestForm form("Bender");
		std::cout << bureaucrat << std::endl;
		std::cout << form;
		std::cout << WHITE << "\nBureaucrat try execute but doesn't has grade enough" << RESET << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		std::cout << WHITE << "\nBureaucrat increment your grade and now has grade enough" << RESET << std::endl;
		for (int i = 0; i < 27; i++)
			bureaucrat.increment();
		std::cout << bureaucrat << std::endl;
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

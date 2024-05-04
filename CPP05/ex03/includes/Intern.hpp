#ifndef INTERN_HPP
# define INTERN_HPP

#include "../includes/Bureaucrat.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

class Intern{
	public:
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);

		Intern &operator=(Intern const &op);

		AForm *makeAForm(std::string name, std::string target);
};

#endif
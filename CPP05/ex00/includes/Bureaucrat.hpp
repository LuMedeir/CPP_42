#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Defines.hpp"

class Bureaucrat{
	private:
		std::string const	name;
		int					grade;
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const& that);
		Bureaucrat(std::string newName, int grade);
		~Bureaucrat(void);
		Bureaucrat &operator=(Bureaucrat const& that);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void 		increment(void);
		void 		decrement(void);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &that);

#endif
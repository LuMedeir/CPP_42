#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "Defines.hpp"

class Bureaucrat;

class Form{
	private:
		std::string const	name;
		bool				sing;
		const int			gradeToEx;
		const int			gradeToSign;
	public:
		Form(void);
		Form(std::string name, int newGradeSign, int newGradeEx);
		Form(Form const &that);
		~Form(void);
		Form &operator=(Form const &src);

		int			getGradeToSign(void) const;
		int			getGradeToEx(void) const;
		std::string	getName(void) const;
		bool		getSing(void) const;
		void		beSigned(Bureaucrat const &that);

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Form const &fr);


#endif
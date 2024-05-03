#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "Defines.hpp"
#include <cstdlib>
#include <ctime> 

class Bureaucrat;

class AForm{
	private:
		std::string const	name;
		bool				sing;
		const int			gradeToEx;
		const int			gradeToSign;
	public:
		AForm(void);
		AForm(std::string name, int newGradeSign, int newGradeEx);
		AForm(AForm const &that);
		~AForm(void);
		AForm &operator=(AForm const &src);

		int			getGradeToSign(void) const;
		int			getGradeToEx(void) const;
		std::string	getName(void) const;
		bool		getSing(void) const;

		virtual void	execute(Bureaucrat const &executor) const = 0;
		void			beSigned(Bureaucrat const &that);

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception{
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, AForm const &fr);


#endif
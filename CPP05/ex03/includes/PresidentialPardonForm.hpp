#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
		std::string	target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
		
		void	execute(const Bureaucrat &executor) const;
};

#endif
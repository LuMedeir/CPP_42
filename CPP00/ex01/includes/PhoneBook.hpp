#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstdlib>
# include "Defines.hpp"
# include "Contact.hpp"

class PhoneBook{
	private:
		Contact	contacts[8];
		int		numberContacts;

	public:
		PhoneBook() : numberContacts(0) {} // Construtor que inicializa numberContacts com 0

		void	addContact(void);
		void	getContacts(void);
		void	getContactInfo(int i);
		int		getNumberContacts(void);
};

#endif
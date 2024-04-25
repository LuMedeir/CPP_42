#include "../includes/PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone;
	std::string	line;

	std::cout << CYAN << "Welcome to the phonebook! 📞" << RESET << std::endl;
	while(true){
		std::cout << WHITE << "\nDo you wish to " PINK << "ADD" WHITE << ", " << PINK << "SEARCH" << WHITE << " or " << PINK <<"EXIT" << WHITE << "?" << RESET << std::endl;
		if (!std::getline(std::cin, line))
			break;
		if (line == "ADD")
			phone.addContact();
		else if (line == "SEARCH")
			phone.getContacts();
		else if (line == "EXIT"){
			std::cout << WHITE << "Bye Bye! 📴 " << RESET << std::endl;
			break;
		}
		else
			std::cout << RED << "Invalid command!" << RESET << std::endl;
	}
}
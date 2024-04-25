#include "../includes/PhoneBook.hpp"

namespace	phoneUtils{
	bool	validName(std::string name){
		if (name.empty())
			return(false);
		for (size_t i = 0; i < name.size(); ++i)
			if (!isalpha(name[i])){
			std::cout << RED << "Invalid name!" << RESET << std::endl;
			return(false);
		}
		return(true);
	}
	bool	validNumber(std::string number){
		if (number.size() < 7 || number.size() > 11){
			std::cout << RED << "Invalid phone number." << RESET << std::endl;
			return(false);
		}
		for (size_t i = 0; i < number.size(); ++i)
		{
			if (!isdigit(number[i])){
			std::cout << RED << "Invalid phone number." << RESET << std::endl;
			return(false);
			}
		}
		return(true);
	}
	bool	validIndex(std::string index, int numberContacts){
		if (index.size() > 1 || !isdigit(index[0])){
			std::cout << RED << "Invalid index." << RESET << std::endl;
			return(false);
		}
		if (std::atol(index.c_str()) > 8 || std::atol(index.c_str()) < 0 || std::atol(index.c_str()) >= numberContacts){
			std::cout << RED << "Invalid index." << RESET << std::endl;
			return(false);
		}
		return(true);
	}
	void	printNamesOfContact(std::string name, bool endl){
		if (name.size() < 10){
			for (size_t i = 0; i < 10 - name.size(); i++)
				std::cout << " ";
			std::cout << name << PURPLE << "|" << RESET;
		}
		else {
			for (size_t i = 0; i < 9; i++)
				std::cout << name[i];
			std::cout << "."<< PURPLE << "|" << RESET;
		}
		if (endl)
			std::cout << std::endl;
	}
}

int	PhoneBook::getNumberContacts(void){
	return(numberContacts);
}

void	PhoneBook::getContacts(void){
	std::string	line;

	if (numberContacts <= 0){
		std::cout << YELLOW << "Your contact list is empty." << RESET << std::endl;
		return;
	}
	std::cout << PURPLE << "|---INDEX--|FIRST-NAME|-LAST-NAME|-NICKNAME-|" << RESET << std::endl;
	for (int i = 0; i < numberContacts; i++){
		std::cout << PURPLE << "|" << RESET << "         " <<  i << PURPLE << "|" << RESET;
		phoneUtils::printNamesOfContact(contacts[i].getFirstName(), false);
		phoneUtils::printNamesOfContact(contacts[i].getLastName(), false);
		phoneUtils::printNamesOfContact(contacts[i].getNickName(), true);
	}
	std::cout << PURPLE << "|----------|----------|----------|----------|" << RESET << std::endl;
	std::cout << WHITE << "Please select a index contact" << RESET << std::endl;
	while (true){
		std::getline(std::cin, line);
		if (line.empty() || !phoneUtils::validIndex(line, numberContacts))
			continue;
		this->getContactInfo(std::atol(line.c_str()));
		break;
	}
	return;
}

void PhoneBook::getContactInfo(int i){
	std::cout << PURPLE << "First name: " << RESET << contacts[i].getFirstName() << std::endl;
	std::cout << PURPLE << "Last name: " << RESET << contacts[i].getLastName() << std::endl;
	std::cout << PURPLE << "Nickname: " << RESET << contacts[i].getNickName() << std::endl;
	std::cout << PURPLE << "Number: " << RESET << contacts[i].getNumber() << std::endl;
	std::cout << PURPLE << "Darkest secret: " << RESET << contacts[i].getDkSecret() << std::endl;
	return;
}

void PhoneBook::addContact(void){
	std::string	line;

	while (true){
		std::cout << WHITE "Please write the first name of the contact" RESET << std::endl;
		std::getline(std::cin, line);
		if (!phoneUtils::validName(line))
			continue;
		contacts[numberContacts % 8].setFirstName(line);
		break;
	}
	while (true){
		std::cout << WHITE "Please write the last name of the contact" RESET << std::endl;
		std::getline(std::cin, line);
		if (!phoneUtils::validName(line))
			continue;
		contacts[numberContacts % 8].setLastName(line);
		break;
	}
	while (true){
		std::cout << WHITE "Please write the nickname of the contact" RESET << std::endl;
		std::getline(std::cin, line);
		if (!phoneUtils::validName(line))
			continue;
		contacts[numberContacts % 8].setNickName(line);
		break;
	}
	while (true){
		std::cout << WHITE "Please write the phone number of the contact" RESET << std::endl;
		std::getline(std::cin, line);
		if (line.empty() || !phoneUtils::validNumber(line))
			continue;
		contacts[numberContacts % 8].setNumber(line);
		break;
	}
	while (true){
		std::cout << WHITE "Please write the darkest secrect of the contact" RESET << std::endl;
		std::getline(std::cin, line);
		if (line.empty())
			continue;
		contacts[numberContacts % 8].setDkSecret(line);
		break;
	}
	if (numberContacts < 8)
		numberContacts++;
	return;
}
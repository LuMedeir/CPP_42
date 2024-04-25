#include "../includes/PhoneBook.hpp"

void	Contact::setFirstName(std::string name){
		firstName = name;
}

void	Contact::setLastName(std::string name){
		lastName = name;
}

void	Contact::setNickName(std::string name){
		nickName = name;
}

void	Contact::setNumber(std::string number){
		this->number = number;
}

void	Contact::setDkSecret(std::string secret){
		dkSecret = secret;
}

std::string	Contact::getFirstName(void){
	return(firstName);
}

std::string	Contact::getLastName(void){
	return(lastName);
}

std::string	Contact::getNickName(void){
	return(nickName);
}

std::string	Contact::getNumber(void){
	return(number);
}

std::string	Contact::getDkSecret(void){
	return(dkSecret);
}
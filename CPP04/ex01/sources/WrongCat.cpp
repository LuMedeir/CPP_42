#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void){
	std::cout << "WrongCat Default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &that){
	std::cout <<  "WrongCat copy constructor called" << std::endl;
	*this = that;
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat  &WrongCat::operator=(WrongCat const &that){
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if(this != &that)
		this->type = that.type;
	return(*this);
}

void    WrongCat::makeSound() const{
	std::cout << CYAN << type << WHITE << ": Meaw? I don't think so... 🦁" << RESET << std::endl;
}
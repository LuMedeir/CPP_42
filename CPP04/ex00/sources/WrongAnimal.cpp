#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Unknown"){
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &that){
	std::cout <<  "WrongAnimal copy constructor called" << std::endl;
	*this = that;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(WrongAnimal const &that){
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if(this != &that)
		this->type = that.type;
	return(*this);
}

std::string WrongAnimal::getType(void) const{
	return(type);
}

void    WrongAnimal::makeSound(void) const{
	std::cout << CYAN << type << WHITE << " makes no sound! 🔇" << WHITE << std::endl;
}
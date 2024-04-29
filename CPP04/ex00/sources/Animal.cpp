#include "../includes/Animal.hpp"

Animal::Animal(void) : type("Unknown"){
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(Animal const &that){
	std::cout <<  "Animal copy constructor called" << std::endl;
	*this = that;
}

Animal::~Animal(void){
	std::cout << "Animal destructor called" << std::endl;
}

Animal  &Animal::operator=(Animal const &that){
	std::cout << "Animal copy assignment operator called" << std::endl;
	if(this != &that)
		this->type = that.type;
	return(*this);
}

std::string Animal::getType(void) const{
	return(type);
}

void    Animal::makeSound(void) const{
	std::cout << CYAN << type << WHITE << " makes no sound! 🔇" << WHITE << std::endl;
}
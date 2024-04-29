#include "../includes/Cat.hpp"

Cat::Cat(void): Animal(){
	std::cout << "Cat Default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(Cat const &that){
	std::cout <<  "Cat copy constructor called" << std::endl;
	*this = that;
}

Cat::~Cat(void){
	std::cout << "Cat destructor called" << std::endl;
}

Cat  &Cat::operator=(Cat const &that){
	std::cout << "Cat copy assignment operator called" << std::endl;
	if(this != &that)
		this->type = that.type;
	return(*this);
}

void    Cat::makeSound() const{
	std::cout << CYAN << type << WHITE << ": Miau! 🐱" << RESET << std::endl;
}
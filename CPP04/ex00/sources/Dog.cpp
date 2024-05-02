#include "../includes/Dog.hpp"

Dog::Dog(void): Animal(){
	std::cout << "Dog Default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(Dog const &that): Animal(that){
	std::cout <<  "Dog copy constructor called" << std::endl;
	*this = that;
}

Dog::~Dog(void){
	std::cout << "Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &that){
	std::cout << "Dog copy assignment operator called" << std::endl;
	if(this != &that)
		this->type = that.type;
	return(*this);
}

void	Dog::makeSound(void) const{
	std::cout << CYAN << type << WHITE << ": Auau! 🐶" << RESET << std::endl;
}
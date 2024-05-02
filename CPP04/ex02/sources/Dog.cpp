#include "../includes/Dog.hpp"

Dog::Dog(void){
	std::cout << "Dog Default constructor called 🐶" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(Dog const &that){
	std::cout <<  "Dog copy constructor called 🐶" << std::endl;
	this->type = that.type;
	this->brain = new Brain(*that.brain);
}

Dog::~Dog(void){
	std::cout << "Dog destructor called 🐶" << std::endl;
	delete brain;
}

Dog	&Dog::operator=(Dog const &that){
	std::cout << "Dog copy assignment operator called 🐶" << std::endl;
	if(this != &that){
		this->type = that.type;
		*this->brain = *that.brain;
	}
	return(*this);
}

void	Dog::makeSound(void) const{
	std::cout << CYAN << type << WHITE << ": Auau! 🐶" << RESET << std::endl;
}

Brain	*Dog::getBrain(void) const{
	return(this->brain);
}
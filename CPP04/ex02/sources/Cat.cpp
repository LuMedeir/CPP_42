#include "../includes/Cat.hpp"

Cat::Cat(void){
	std::cout << "Cat Default constructor called 🐱" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(Cat const &that){
	std::cout <<  "Cat copy constructor called 🐱" << std::endl;
	this->type = that.type;
	this->brain = new Brain(*that.brain);
}

Cat::~Cat(void){
	std::cout << "Cat destructor called 🐱" << std::endl;
	delete brain;
}

Cat	&Cat::operator=(Cat const &that){
	std::cout << "Cat copy assignment operator called 🐱" << std::endl;
	if(this != &that){
		this->type = that.type;
		*this->brain = *that.brain;
	}
	return(*this);
}

void	Cat::makeSound() const{
	std::cout << CYAN << type << WHITE << ": Miau! 🐱" << RESET << std::endl;
}

Brain	*Cat::getBrain(void) const{
	return(this->brain);
}
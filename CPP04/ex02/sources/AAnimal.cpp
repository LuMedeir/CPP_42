#include "../includes/AAnimal.hpp"

AAnimal::AAnimal(void) : type("Unknown"){
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &that){
	std::cout <<  "AAnimal copy constructor called" << std::endl;
	*this = that;
}

AAnimal::~AAnimal(void){
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &that){
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if(this != &that)
		this->type = that.type;
	return(*this);
}

std::string AAnimal::getType(void) const{
	return(type);
}

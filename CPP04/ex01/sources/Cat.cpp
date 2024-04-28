#include "../includes/Cat.hpp"

Cat::Cat(void): Animal(){
    std::cout << "Cat Default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(Cat const &that){
    std::cout <<  "Cat copy constructor called" << std::endl;
    brain = new Brain();
    *this = that;
}

Cat::~Cat(void){
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

Cat  &Cat::operator=(Cat const &that){
    std::cout << "Cat copy assignment operator called" << std::endl;
	if(this != &that){
        this->type = that.type;
        *brain = *(that.brain);
    }
    return(*this);
}

void    Cat::makeSound() const{
    std::cout << "Miau! 🐱" << std::endl;
}

Brain   *Cat::getBrain(void) const{
    return(brain);
}
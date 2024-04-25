#include "../includes/Zombie.hpp"

Zombie::Zombie(void){
	std::cout << WHITE << "Zombie created 🧟" << RESET << std::endl;
}

Zombie::~Zombie(void){
	std::cout << WHITE << getName() << RED << " destroyed 💀" << RESET << std::endl;
}

void	Zombie::setName(std::string newName){
	name = newName;
}

std::string	Zombie::getName(void){
	return(name);
}

void	Zombie::announce(void){
	std::cout << WHITE << getName() << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name){
	this->name = name;
}

HumanB::~HumanB(){
}

void	HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}

void	HumanB::setName(std::string name){
	this->name = name;
}

void		HumanB::attack(){
	if(weapon != NULL)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " attacks with their hand" << std::endl;
}
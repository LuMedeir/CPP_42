#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon){
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA(){
}

void	HumanA::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}

void	HumanA::setName(std::string name){
	this->name = name;
}

void		HumanA::attack(){
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
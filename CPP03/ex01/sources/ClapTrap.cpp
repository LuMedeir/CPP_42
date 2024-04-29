#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Unknown"), hitPoint(10), energyPoint(10), attackDamage(0){
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoint(10), attackDamage(0){
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &that){
	std::cout <<  "ClapTrap copy constructor called" << std::endl;
	*this = that;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &that){
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if(this != &that){
		this->name = that.getName();
		this->hitPoint = that.getHitPoints();
		this->energyPoint = that.getEnergyPoint();
		this->attackDamage = that.getAttackDamage();
	}
	return(*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::setHitPoints(int newHitPoint){
	this->hitPoint = newHitPoint;
}

int	ClapTrap::getHitPoints(void) const{
	return(hitPoint);
}

void	ClapTrap::setEnergyPoint(int newEnergyPoint){
	this->energyPoint = newEnergyPoint;
}

int	ClapTrap::getEnergyPoint(void) const{
	return(energyPoint);
}

void	ClapTrap::setAttackDamage(int newAttackDamage){
	this->energyPoint = newAttackDamage;
}

int	ClapTrap::getAttackDamage(void) const{
	return(attackDamage);
}

void	ClapTrap::setName(std::string newName){
	this->name = newName;
}

std::string ClapTrap::getName(void) const{
	return(name);
}

void	ClapTrap::attack(const std::string &target){
	if (hitPoint <=0){
		std::cout << RED << name << "is already dead! 😭" << RESET << std::endl;
		return;
	}
	else if (energyPoint == 0){
		std::cout << RED << name << " is out of energy!🔋" << RESET << std::endl;
		return;
	}
	std::cout << RED << name << " attacks " << target <<
		", causing " << attackDamage << " points of damage! 🛡️🗡️" RESET << std::endl;
	energyPoint -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (hitPoint <= 0){
		std::cout << CYAN << name << "is already dead! 😭" << RESET << std::endl;
		return;
	}
	if (amount >= static_cast<unsigned int>(hitPoint))
		std::cout << CYAN << name << "is dead! 💀" << RESET << std::endl;
	else
		std::cout << CYAN << name << " takes " << amount << " points of Damage! 🤕" << RESET << std::endl;
	this->hitPoint -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (hitPoint <=0){
		std::cout << PURPLE << name << "is already dead! 😭" << RESET << std::endl;
		return;
	}
	else if (energyPoint == 0){
		std::cout << PURPLE << name << " is out of energy!🔋" << RESET << std::endl;
		return;
	}
	std::cout << PURPLE  << name << " is repaired with " <<
		amount << " points of energy! 🩹" RESET << std::endl;
	this->hitPoint += amount;
	this->energyPoint -= 1;
}
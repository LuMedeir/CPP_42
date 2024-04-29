#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap(){
    std::cout << "ScavTrap default constructor called" << std::endl;
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(){
    std::cout << "ScavTrap name constructor called" << std::endl;
    this->name = name;
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &that): ClapTrap(){
    std::cout <<  "ScavTrap copy constructor called" << std::endl;
	*this = that;
}

ScavTrap::~ScavTrap(void){
    std::cout <<  "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &that){
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if(this != &that){
		this->name = that.getName();
		this->hitPoint = that.getHitPoints();
		this->energyPoint = that.getEnergyPoint();
		this->attackDamage = that.getAttackDamage();
	}
	return(*this);
}

void	ScavTrap::attack(const std::string &target){
	if (hitPoint <=0){
		std::cout << RED << "ScavTrap " << name << "is already dead! 😭" << RESET << std::endl;
		return;
	}
	else if (energyPoint == 0){
		std::cout << RED << "ScavTrap " << name << " is out of energy!🔋" << RESET << std::endl;
		return;
	}
	std::cout << RED "ScavTrap " << name << " attacks " << target <<
		", causing " << attackDamage << " points of damage! 🛡️🗡️" RESET << std::endl;
	energyPoint -= 1;
}

void    ScavTrap::guardGate(void){
    std::cout << YELLOW "ScavTrap " << getName()
		<< " has entered in Gate keeper mode. 💂" << RESET << std::endl;
}
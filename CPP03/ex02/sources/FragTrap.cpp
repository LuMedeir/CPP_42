# include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap(){
    std::cout << "FragTrap default constructor called" << std::endl;
    hitPoint = 100;
    energyPoint = 100;
    attackDemage = 300;
}

FragTrap::FragTrap(std::string name): ClapTrap(){
    std::cout << "FragTrap name constructor called" << std::endl;
    this->name = name;
    hitPoint = 100;
    energyPoint = 50;
    attackDemage = 20;
}

FragTrap::FragTrap(FragTrap const &that): ClapTrap(){
    std::cout <<  "FragTrap copy constructor called" << std::endl;
	*this = that;
}

FragTrap::~FragTrap(void){
    std::cout <<  "FragTrap destructor called" << std::endl;
}

FragTrap    &FragTrap::operator=(const FragTrap &that){
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if(this != &that){
		this->name = that.getName();
		this->hitPoint = that.getHitPoints();
		this->energyPoint = that.getEnergyPoint();
		this->attackDemage = that.getAttackDemage();
	}
	return(*this);
}

void    FragTrap::highFivesGuys(void){
    std::cout << PINK << "High five guys!" << RESET << std::endl;
}
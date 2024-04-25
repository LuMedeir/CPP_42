#include "../includes/Harl.hpp"

void	Harl::debug(void){
	std::cout << PURPLE << "[ DEBUG ]\r\n" << WHITE << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" 
		<< RESET << std::endl;
}

void	Harl::info(void){
	std::cout << PURPLE << "[ INFO ]\r\n" << WHITE << "I cannot believe adding extra bacon costs more money. You didn’t put "
		<< "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void	Harl::warning(void){
	std::cout << PURPLE << "[ WARNING ]\r\n" << WHITE << "I think I deserve to have some extra bacon for free. I’ve been coming for "
		<< "years whereas you started working here since last month." << RESET << std::endl;
}

void	Harl::error(void){
	std::cout << PURPLE << "[ ERROR ]\r\n" << WHITE << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void	Harl::complain(std::string level){
	void(Harl::*methods[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i;
	for (i = 0; i < 4 && levels[i] != level; i++);
	(this->*methods[i])();
}
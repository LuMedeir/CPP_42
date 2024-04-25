#include "../includes/Harl.hpp"

int	main(int argc, char **argv){
	Harl	complainer;

	if (argc != 2)
		std::cout << RED "Error: " << WHITE << "Invalid number of arguments" << RESET << std::endl;
	complainer.complain(argv[1]);
}
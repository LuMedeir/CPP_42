#include "../includes/RPN.hpp"

int	main(int argc, char **argv){
	RPN rpn;

	if (argc != 2) {
		std::cout << RED "Error: invalid number of arguments."<< std::endl;
		return (1);
	}
	try {
		std::cout << WHITE << rpn.calculator(argv[1]) << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return (0);
}

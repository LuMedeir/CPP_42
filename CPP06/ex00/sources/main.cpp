#include "../includes/ScalarConverter.hpp"

int	main(int argc, char **argv){
	if (argc != 2){
		std::cout << RED << "Error: " << WHITE
			<< "invalid number of arguments" << RESET << std::endl;
			return(-1);
	}
	ScalarConverter::convert(argv[1]);
	return(0);
}
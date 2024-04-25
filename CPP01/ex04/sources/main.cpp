#include "../includes/Replace.hpp"

void	printError(){
	std::cout << RED << "Error: " << WHITE << "Invalid number of arguments" << std::endl;
	std:: cout << "******* Please follow the example below: \"./replace " << PURPLE << "[file name] [s1] [s2]\" "
		<< WHITE << "*******"  << RESET << std::endl;
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 4)
		printError();

	std::string	inFile = readfile(argv[1]);
	std::string	outFile = (std::string)argv[1] + ".replace";
	replace(inFile, outFile, (std::string)argv[2], (std::string)argv[3]);
	return(0);
}
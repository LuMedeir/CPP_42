#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv){
	if(argc != 2){
		std::cout << RED << "Error: " << WHITE << "could not open file." << RESET << std::endl;
		return(1);
	}
	try {
		BitcoinExchange exchange;
		exchange.readInput(argv[1]);  
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
}
#include "../includes/Replace.hpp"

namespace utils{
	bool	checkInputFile(std::ifstream &file){
		if(file.is_open())
			return(true);
		else
			std::cout << RED << "Error: " << WHITE << "Invalid input file" << RESET << std::endl;
		return(false);
	}
	bool	checkOutputFile(std::ofstream &file){
		if(file.is_open())
			return(true);
		else
			std::cout << RED << "Error: " << WHITE << "Invalid output file" << RESET << std::endl;
		return(false);
	}
}

std::string readfile(const std::string filename){
	std::ifstream file(filename.c_str());
	std::string content;
	std::string line;

	if (utils::checkInputFile(file)) {
		while (std::getline(file, line)) {
			content += line + "\n";
		}
		file.close();
	}
	return(content);
}

void	replace(std::string inFile, std::string outFile, std::string s1, std::string s2){
	std::ofstream file(outFile.c_str());
	if (!utils::checkOutputFile(file))
		return;

	size_t startPos = 0;
	size_t foundPos = inFile.find(s1);
	while (foundPos != std::string::npos) // "std::string::npos" é uma constante estática da classe std::string. Normalmente, é retornada por várias funções da classe std::string, como find, quando a substring buscada não é encontrada na string.
	{
		file << inFile.substr(startPos, foundPos - startPos) << s2;

		startPos = foundPos + s1.length();
		foundPos = inFile.find(s1, startPos);
	}
	file << inFile.substr(startPos);
	file.close();
}
#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>
# include "Defines.hpp"

void	replace(std::string inFile, std::string outFile,
			std::string s1, std::string s2);
std::string readfile(const std::string filename);

#endif
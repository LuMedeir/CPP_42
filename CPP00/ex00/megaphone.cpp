#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for(int i = 1; i < argc; i++) {
			std::string arg = argv[i];
			for(size_t j = 0; j < arg.length(); j++)
				std::cout << char(toupper(argv[i][j]));
		}
	}
	std::cout << std::endl;
}

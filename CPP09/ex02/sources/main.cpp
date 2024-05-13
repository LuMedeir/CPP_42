#include "../includes/PmergeMe.hpp"

bool isSorted(int argc, char* argv[]) {
	for (int i = 1; i < argc - 1; ++i) {
		int current = std::atoi(argv[i]);
		int next = std::atoi(argv[i + 1]);
		if (current > next) {
			return false;
		}
	}
	return true;
}

int	main(int argc, char **argv){
	if (argc == 1){
		std::cout << "Error: no arguments" << std::endl;
		return (1);
	}
	if (isSorted(argc, argv)){
		std::cout << RED "Error: array already sorted."<< std::endl;
		return (1);
	}
	PmergeMe	p;
	p.sort(argc, argv);
	return (0);
}
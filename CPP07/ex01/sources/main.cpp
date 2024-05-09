#include "../includes/iter.hpp"

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	std::string const strArray[] = {"one", "two", "three", "four", "five"};
	float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	double const doubleArray[] = {1.11, 2.22, 3.33, 4.44, 5.55};
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << WHITE << std::endl;
	std::cout << "----------------------- ITER TEST -----------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- INT TEST ------------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;
	::iter<int>(intArray, 5, ::randonColorPrint<int>);
	std::cout << WHITE << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- STRING TEST ---------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	::iter(strArray, 5, ::randonColorPrint<std::string>);
	std::cout << WHITE << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- FLOAT TEST ----------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;
	::iter(floatArray, 5, ::randonColorPrint<float>);
	std::cout << WHITE << "---------------------------------------------------------------" << std::endl;
	std::cout << "------------------------ DOUBLE TEST --------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;
	::iter(doubleArray, 5, ::randonColorPrint<double>);
	std::cout << WHITE << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- CHAR TEST -----------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;
	::iter(charArray, 5, ::randonColorPrint<char>);
	std::cout << WHITE << "---------------------------------------------------------------" << RESET << std::endl;
	return (0);
}
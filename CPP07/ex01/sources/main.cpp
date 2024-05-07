#include "../includes/iter.hpp"

int main(void)
{
	int int_array[] = {1, 2, 3, 4, 5};
	std::string const str_array[] = {"one", "two", "three", "four", "five"};
	float float_array[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	double const double_array[] = {1.11, 2.22, 3.33, 4.44, 5.55};
	char char_array[] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << WHITE << std::endl;
	std::cout << "----------------------- ITER TEST -----------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- INT TEST ------------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;
	::iter<int>(int_array, 5, ::randonColorPrint<int>);
	std::cout << WHITE << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- STRING TEST ---------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	::iter(str_array, 5, ::randonColorPrint<std::string>);
	std::cout << WHITE << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- FLOAT TEST ----------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;
	::iter(float_array, 5, ::randonColorPrint<float>);
	std::cout << WHITE << "---------------------------------------------------------------" << std::endl;
	std::cout << "------------------------ DOUBLE TEST --------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;
	::iter(double_array, 5, ::randonColorPrint<double>);
	std::cout << WHITE << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- CHAR TEST -----------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;
	::iter(char_array, 5, ::randonColorPrint<char>);
	std::cout << WHITE << "---------------------------------------------------------------" << RESET << std::endl;
	return (0);
}
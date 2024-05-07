#include "../includes/Base.hpp"

int main(void){

	std::cout << PURPLE << "--------------------- DYNAMIC CAST TEST -----------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Test " << i + 1 << "..." << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout << "Generating random class..." << std::endl;
		Base *base = generate();
		std::cout << "Identifying class with pointer..." << std::endl;
		identify(base);
		std::cout << "Identifying class with reference..." << std::endl;
		identify(*base);
		delete base;
		std::cout << "---------------------------------------------------------------" << std::endl;
	}
}
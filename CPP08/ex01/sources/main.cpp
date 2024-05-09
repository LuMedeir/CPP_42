#include "../includes/Span.hpp"

int main()
{
	std::cout << PURPLE << std::endl;
	std::cout << "------------------ EASYFIND SUBJECT TEST ----------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << PURPLE << std::endl;
	std::cout << "------------------- EASYFIND MY OWN TEST ----------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "-------------------------- TEST 1 -----------------------------" << RESET << std::endl;
	Span sp1 = Span(5);
	sp1.addNumber(10);
	sp1.addNumber(23);
	sp1.addNumber(-3);
	sp1.addNumber(18);
	sp1.addNumber(-20);

	std::cout << CYAN << "Shortest span: " << WHITE << sp1.shortestSpan() << std::endl;
	std::cout << CYAN << "Longest span: " << WHITE << sp1.longestSpan() << std::endl;
	std::cout << RESET;

	std::cout << PURPLE << "-------------------------- TEST 2 -----------------------------" << RESET << std::endl;
	Span sp2 = Span(10);
	sp2.addNumber(10);
	sp2.addNumber(23);
	sp2.addNumber(-3);
	sp2.addNumber(18);
	sp2.addNumber(-20);
	sp2.addNumber(1250);
	sp2.addNumber(-1);
	sp2.addNumber(54);
	sp2.addNumber(90);
	sp2.addNumber(8);

	std::cout << CYAN << "Shortest span: " << WHITE << sp2.shortestSpan() << std::endl;
	std::cout << CYAN << "Longest span: " << WHITE << sp2.longestSpan() << std::endl;
	std::cout << RESET;

	std::cout << PURPLE << "------------------- 10000 ADDNUMBER TEST ----------------------" << RESET << std::endl;
	Span sp3 = Span(10000);
	std::srand(time(NULL));
	for (int i = 0; i < 10000; i++)
		sp3.addNumber(std::rand());

	std::cout << CYAN << "Shortest span: " << WHITE << sp3.shortestSpan() << std::endl;
	std::cout << CYAN << "Longest span: " << WHITE << sp3.longestSpan() << std::endl;
	std::cout << RESET;

	std::cout << PURPLE << "------------------- 10000 ADDNUMBERS TEST ---------------------" << RESET << std::endl;
	Span sp4(10000);
	std::vector<int> vec;
	for (int i = 0; i < 10000; i++)
		vec.push_back(std::rand());
	sp4.addNumbers(vec.begin(), vec.end());

	std::cout << CYAN << "Shortest span: " << WHITE << sp4.shortestSpan() << std::endl;
	std::cout << CYAN << "Longest span: " << WHITE << sp4.longestSpan() << std::endl;
	std::cout << RESET;

	std::cout << PURPLE << "---------------------- EXCEPTION TEST -------------------------" << std::endl;
	std::cout << "------------------ Try to add in full vector ------------------" << RESET << std::endl;
	Span sp5 = Span(5);
	try
	{
		sp5.addNumber(10);
		sp5.addNumber(23);
		sp5.addNumber(3);
		sp5.addNumber(18);
		sp5.addNumber(20);
		sp5.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << PURPLE << "------ Try to find shortest and longest in a empty vector -------" << RESET << std::endl;
	Span sp6 = Span(5);

	try
	{
		std::cout << CYAN << "Shortest span: " << WHITE << sp6.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		try
	{
		std::cout << CYAN << "Longest span: " << WHITE << sp6.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << RESET;

	std::cout << PURPLE << "--- Try to find shortest and longest vector without enough values ---" << RESET << std::endl;
	Span sp7 = Span(5);

	sp7.addNumber(1);
	try
	{
		std::cout << CYAN << "Shortest span: " << WHITE << sp7.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		try
	{
		std::cout << CYAN << "Longest span: " << WHITE << sp7.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << RESET;

	return 0;
}
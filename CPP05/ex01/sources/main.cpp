#include "../includes/Form.hpp"

int	main(void){
	std::cout << PURPLE << std::endl;
	std::cout << "------------------------- FORM TEST ---------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------\n" << RESET << std::endl;
	
	try {
		std::cout << PURPLE << "----------------------- Higher sign grade -----------------------" << RESET << std::endl;
		Form f("singHigher", -1, 1);
	}
	catch (std::exception & e){
		std::cout << CYAN << "Exception: " << WHITE << e.what() << RESET << std::endl;
	}

	try {
		std::cout << PURPLE << "----------------------- Higher exec grade -----------------------" << RESET << std::endl;
		Form f("execHigher", 1, -1);
	}
	catch (std::exception & e){
		std::cout << CYAN << "Exception: " << WHITE << e.what() << RESET << std::endl;
	}
	try {
		std::cout << PURPLE << "----------------------- lower sign grade -----------------------" << RESET << std::endl;
		Form f("singLower", 151, 1);
	}
	catch (std::exception & e){
		std::cout << CYAN << "Exception: " << WHITE << e.what() << RESET << std::endl;
	}

	try {
		std::cout << PURPLE << "----------------------- lower exec grade -----------------------" << RESET << std::endl;
		Form f("execLower", 1, 151);
	}
	catch (std::exception & e){
		std::cout << CYAN << "Exception: " << WHITE << e.what() << RESET << std::endl;
	}

	std::cout << PURPLE << std::endl;
	std::cout << "\n---------------------- BUREAUCRAT TEST ------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------\n" << RESET << std::endl;
	try{
		std::cout << PURPLE << "---------------------- Valid grade to sing ----------------------" << RESET << std::endl;
		Bureaucrat b1("Leo", 20);
		Form f1("f1", 25, 5);
		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;
		std::cout << WHITE << "Bureaucrat " << b1.getName() << " tries to sing the form" << f1.getName() << RESET << std::endl;
		b1.signForm(f1);
		std::cout << "\n" << std::endl;
	}
	catch (std::exception & e){
		std::cout << CYAN << "Exception: " << WHITE << e.what() << RESET << std::endl;
	}
	try {
		std::cout << PURPLE << "--------------------- invalid grade to sing ---------------------" << RESET << std::endl;
		Bureaucrat b2("Katy", 55);
		Form f2("f2", 20, 5);
		std::cout << b2 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << WHITE << "Bureaucrat " << b2.getName() << " tries to sing the form" << f2.getName() << RESET << std::endl;
		b2.signForm(f2);
		std::cout << "\n" << std::endl;
	}
	catch (std::exception & e){
		std::cout << CYAN << "Exception: " << WHITE << e.what() << RESET << std::endl;
	}
	return (0);
}
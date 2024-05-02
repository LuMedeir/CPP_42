#include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	std::cout << PURPLE << std::endl;
	std::cout << "----------------------- SUBJECT TEST -------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------\n" << RESET << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog(); // Criação de um objeto Dog através de um ponteiro para Animal
	const Animal* i = new Cat();// Criação de um objeto Cat através de um ponteiro para Animal
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
		
	std::cout << PURPLE << std::endl;
	std::cout << "------------------------- MY OWN TEST -------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------set objects--------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------\n" << RESET << std::endl;

	Dog	dog;
	Cat	cat;

	std::cout << PURPLE << std::endl;
	std::cout << "\n--------------------------------------------------------------" << std::endl;
	std::cout << "you can see that cat and dog have the right type and the righ song" << std::endl;
	std::cout << "--------------------------------------------------------------\n" << std::endl;

	std::cout << WHITE << dog.getType() << " " << std::endl;
	std::cout << cat.getType() << std::endl;
	dog.makeSound();
	cat.makeSound();

	std::cout << PURPLE << std::endl;
	std::cout << "-------------------set objects by pointer----------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------\n" << RESET << std::endl;

	const WrongAnimal* wAnimal = new WrongCat();
	const WrongCat wCat;

	std::cout << PURPLE << std::endl;
	std::cout << "\n--------------------------------------------------------------" << std::endl;
	std::cout << "you can see that both have the right type" << std::endl;
	std::cout << "--------------------------------------------------------------\n" << std::endl;

	std::cout << WHITE << wCat.getType() << std::endl;
	std::cout << wAnimal->getType() << std::endl;

	std::cout << PURPLE << std::endl;
	std::cout << "\n--------------------------------------------------------------" << std::endl;
	std::cout << "----now you can see that only WrongCat have the wrong sound-----" << std::endl;
	std::cout << "--------------------------------------------------------------\n" << RESET << std::endl;

	wCat.makeSound();
	wAnimal->makeSound(); //will output the WrongAnimal sound!

	std::cout << PURPLE << std::endl;
	std::cout << "\n--------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------Delete all---------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------\n" << RESET << std::endl;


	delete meta;
	delete i;
	delete j;
	delete wAnimal;

	return 0;
}

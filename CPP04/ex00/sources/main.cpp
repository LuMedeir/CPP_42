#include "../includes/WrongAnimal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	std::cout << PURPLE << std::endl;
	std::cout << "----------------------- SUBJECT TEST -------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------\n" << RESET << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
		std::cout << PURPLE << std::endl;
	std::cout << "----------------------- MY OWN TEST -------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------\n" << RESET << std::endl;

	const WrongAnimal* wrong1 = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound(); //will output the cat sound!
	wrong1->makeSound();

	return 0;
}
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
		std::cout << CYAN << std::endl;
	std::cout << "----------------------- SUBJECT TEST -------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------\n" << RESET << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << CYAN<< std::endl;
	std::cout << "\n\n------------------------- MY OWN TEST -------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------\n\n" << RESET << std::endl;
	
	std::cout << PURPLE << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------Delete test--------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Fill the Animal array with 6 Animals." << std::endl;
	std::cout << "Half of them are Cats and the other half are Dogs." << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET <<std::endl;

	const Animal *animals[6];
	
	for(int i = 0; i < 6; i++){
		if (i < 3)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << PURPLE << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Delete directly dogs and cats" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;

	for(int i = 0; i < 6; i++)
		delete animals[i];

	std::cout << CYAN << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "---------------------Deep copy dog test 🐶---------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;

	Dog *dog1 = new Dog();
	Dog *dog2 = new Dog();

	dog1->getBrain()->setIdeas("quero sachê", 0);
	dog1->getBrain()->setIdeas("vou correr atrás da moto", 1);
	dog2->getBrain()->setIdeas("quero ração", 0);
	dog2->getBrain()->setIdeas("vou morder a canela daquele motoqueiro", 1);

	std::cout << PURPLE << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Fist dog's ideas" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;

	std::cout << WHITE << "Dog1: " << dog1->getBrain()->getIdeas(0) << "💭" << std::endl;
	std::cout << WHITE << "Dog1: " << dog1->getBrain()->getIdeas(1) << "💭" << std::endl;
	std::cout << WHITE << "Dog2: " << dog2->getBrain()->getIdeas(0) << "💭" << std::endl;
	std::cout << WHITE << "Dog2: " << dog2->getBrain()->getIdeas(1) << "💭" << std::endl;

	std::cout << PURPLE << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Dog1 gets Dog2 ideas" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;

	*dog1 = *dog2;

	std::cout << WHITE << "Dog1: " << dog1->getBrain()->getIdeas(0) << "💭" << std::endl;
	std::cout << WHITE << "Dog1: " << dog1->getBrain()->getIdeas(1) << "💭" << std::endl;
	std::cout << WHITE << "Dog2: " << dog2->getBrain()->getIdeas(0) << "💭" << std::endl;
	std::cout << WHITE << "Dog2: " << dog2->getBrain()->getIdeas(1) << "💭" << std::endl;

	std::cout << PURPLE << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Now, delete Dog2 shouldn't affect Dog1" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	std::cout << "deleting. dog2.." << RESET << std::endl;
	delete dog2;
	std::cout << PURPLE << "Dog1 ideas:" << RESET << std::endl;
	std::cout << WHITE << "Dog1: " << dog1->getBrain()->getIdeas(0) << "💭" << std::endl;
	std::cout << WHITE << "Dog1: " << dog1->getBrain()->getIdeas(1) << "💭\n" << std::endl;

	delete dog1;


	std::cout << CYAN<< std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "---------------------Deep copy cat test 🐱---------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;

	Cat *cat1 = new Cat();
	Cat *cat2 = new Cat();

	cat1->getBrain()->setIdeas("quero sachê", 0);
	cat1->getBrain()->setIdeas("vou derrubar tudo de cima da mesa", 1);
	cat2->getBrain()->setIdeas("quero ração", 0);
	cat2->getBrain()->setIdeas("vou pedir carinho e depois atacar", 1);

	std::cout << PURPLE << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Fist dog's ideas" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;

	std::cout << WHITE << "Cat1: " << cat1->getBrain()->getIdeas(0) << "💭" << std::endl;
	std::cout << WHITE << "Cat1: " << cat1->getBrain()->getIdeas(1) << "💭" << std::endl;
	std::cout << WHITE << "Cat2: " << cat2->getBrain()->getIdeas(0) << "💭" << std::endl;
	std::cout << WHITE << "Cat2: " << cat2->getBrain()->getIdeas(1) << "💭" << std::endl;

	std::cout << PURPLE << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "cat1 gets cat2 ideas" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;

	*cat1 = *cat2;

	std::cout << WHITE << "Cat1: " << cat1->getBrain()->getIdeas(0) << "💭" << std::endl;
	std::cout << WHITE << "Cat1: " << cat1->getBrain()->getIdeas(1) << "💭" << std::endl;
	std::cout << WHITE << "Cat2: " << cat2->getBrain()->getIdeas(0) << "💭" << std::endl;
	std::cout << WHITE << "Cat2: " << cat2->getBrain()->getIdeas(1) << "💭" << std::endl;

	std::cout << PURPLE << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Now, delete cat2 shouldn't affect cat1" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	std::cout << "deleting cat2..." << RESET << std::endl;
	delete cat2;
	std::cout << PURPLE << "Cat1 ideas:" << RESET << std::endl;
	std::cout << WHITE << "Cat1: " << cat1->getBrain()->getIdeas(0) << "💭" << std::endl;
	std::cout << WHITE << "Cat1: " << cat1->getBrain()->getIdeas(1) << "💭\n" << std::endl;

	delete cat1;

	std::cout << CYAN<< std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "-------------------Copy constructor test 🐱--------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;

	Dog dog3;
	dog3.getBrain()->setIdeas("quero sachê", 0);
	Dog dog4(dog3);

	std::cout << PURPLE << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Fist dog's ideas" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;

	std::cout << WHITE << "Dog1: " << dog3.getBrain()->getIdeas(0) << "💭" << std::endl;
	std::cout << WHITE << "Dog2: " << dog4.getBrain()->getIdeas(0) << "💭" << std::endl;
	std::cout << PURPLE << std::endl;

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "change dog1 ideas shouldn't affect dog2 ideas" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;

	dog3.getBrain()->setIdeas("quero ração", 0);
	std::cout << WHITE << "Dog1: " << dog3.getBrain()->getIdeas(0) << "💭" << std::endl;
	std::cout << WHITE << "Dog2: " << dog4.getBrain()->getIdeas(0) << "💭\n " << std::endl;
	return 0;
}

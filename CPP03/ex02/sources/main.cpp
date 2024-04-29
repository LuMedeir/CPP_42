#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "----------------------- SCARVTRAP TEST -------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "ClapTrap a is created with name 'Spartan'" << std::endl;
	std::cout << "ScavTrap b is created with name 'Troian'" << std::endl;
	std::cout << "FragTrap c is created with name 'Persian'" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	ClapTrap a("Spartan");
	ScavTrap b("Troian");
	FragTrap c("Persian");

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Spartan attacks Troian" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Spartan attacks Persian" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	a.attack(c.getName());
	c.takeDamage(a.getAttackDamage());

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Troian attacks Spartan" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	b.attack(a.getName());
	a.takeDamage(b.getAttackDamage());

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Spartan repairs himself with 20 hit points" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	a.beRepaired(20);

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Troian attacks Persian" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	
	b.attack(c.getName());
	c.takeDamage(b.getAttackDamage());

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Persian repairs himself with 20 hit points" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	c.beRepaired(20);

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Persian attacks Troian 4 times" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		c.attack(b.getName());
		b.takeDamage(c.getAttackDamage());
		std::cout << std::endl;
	}

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Troian tries repairs himself with 20 hit points" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	b.beRepaired(30);

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Troian give up from war, and he is now a gatekeeper" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	b.guardGate();

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Persian are happy and he is now a high five guy" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	c.highFivesGuys();

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Spartan, Troian and Persian are destroyed" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	
	return (0);
}
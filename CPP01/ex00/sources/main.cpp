#include "../includes/Zombie.hpp"

int	main(void)
{
	Zombie	*zombie = newZombie("Serena");
	zombie->announce();

	randomChump("Blair");
	delete zombie;
}
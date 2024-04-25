#include "../includes/Zombie.hpp"

int	main(void)
{
	int		max = 10;
	Zombie	*horde = zombieHorde(max, "Blair");

	for(int i = 0; i < max; i++)
		horde[i].announce();
	delete [] horde;
	return(0);
}
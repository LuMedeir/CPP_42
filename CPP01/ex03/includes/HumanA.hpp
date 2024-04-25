#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanA{
	private:
		std::string	name;
		Weapon	*weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	setWeapon(Weapon &weapon);
		void	setName(std::string type);
		void	attack();
};

#endif
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &that);
		~ScavTrap(void);
		ScavTrap &operator=(ScavTrap const &that);

		void	guardGate(void);
		void	attack(const std::string& target);
};

#endif
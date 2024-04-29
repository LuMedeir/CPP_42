#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &that);
		~FragTrap(void);
		FragTrap &operator=(FragTrap const &that);

		void	highFivesGuys(void);
};

#endif
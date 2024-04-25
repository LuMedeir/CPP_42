#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include "Defines.hpp"

class ClapTrap{
	private:
		std::string name;
		int	hitPoint;
		int	energyPoint;
		int	attackDemage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &that);
		~ClapTrap(void);
		ClapTrap &operator=(const ClapTrap &that);

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		void		setHitPoints(int newHitPoint);
		int			getHitPoints(void) const;
		void		setEnergyPoint(int newEnergyPoint);
		int			getEnergyPoint(void) const;
		void		setAttackDemage(int newAttackDemage);
		int			getAttackDemage(void) const;
		void		setName(std::string newName);
		std::string	getName(void) const;
};

#endif
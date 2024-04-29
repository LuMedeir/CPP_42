#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Defines.hpp"

class Animal{
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(Animal const &that);
		~Animal(void);
		Animal &operator=(Animal const &that);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif
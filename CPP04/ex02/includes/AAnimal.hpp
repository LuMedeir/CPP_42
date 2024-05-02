#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Defines.hpp"

class AAnimal{
	protected:
		std::string type;
	public:
		AAnimal(void);
		AAnimal(AAnimal const &that);
		virtual ~AAnimal(void);
		AAnimal &operator=(AAnimal const &that);

		virtual void	makeSound(void) const = 0; // não possui implementação.
		std::string		getType(void) const;
};

#endif
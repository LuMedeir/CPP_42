#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog(void);
		Dog(Dog const &that);
		~Dog(void);
		Dog &operator=(Dog const &that);

		virtual void	makeSound(void) const;
};

#endif
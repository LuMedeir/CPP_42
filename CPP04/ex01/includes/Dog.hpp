#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain *brain;
	public:
		Dog(void);
		Dog(Dog const &that);
		virtual ~Dog(void);
		Dog &operator=(Dog const &that);

		virtual void	makeSound(void) const;
		Brain			*getBrain(void) const;
};

#endif
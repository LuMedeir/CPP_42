#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal{
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
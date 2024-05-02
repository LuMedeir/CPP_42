#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal{
	private:
		Brain *brain;
	public:
		Cat(void);
		Cat(Cat const &that);
		virtual ~Cat(void);
		Cat &operator=(Cat const &that);

		virtual void	makeSound(void) const;
		Brain			*getBrain(void) const;
};

#endif
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
		WrongCat(void);
		WrongCat(WrongCat const &that);
		~WrongCat(void);
		WrongCat &operator=(WrongCat const &that);

		void	makeSound(void) const;
};

#endif
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include "Defines.hpp"

class WrongAnimal{
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &that);
		virtual ~WrongAnimal(void);
		WrongAnimal &operator=(WrongAnimal const &that);

		void makeSound(void) const;
		std::string getType(void) const;
};

#endif
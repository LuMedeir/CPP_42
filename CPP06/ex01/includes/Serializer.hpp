#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"
# include "Defines.hpp"

class Serializer{
	private:
		Serializer(void);
		~Serializer(void);
		Serializer(Serializer const &copy);
		Serializer &operator=(Serializer const &rhs);

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
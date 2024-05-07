#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
#include <iostream>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define WHITE "\033[1;37m"
# define CYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[1;35m"
# define PINK "\033[95m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# include "../sources/Array.tpp"


template <typename T>
class Array{
	private:
		T*				array;
		unsigned int	sizeArray;

	public:
		Array(void);
		Array(Array const& that);
		Array(unsigned int n);
		~Array(void);

		Array&	operator=(Array const& that);
		T&		operator[](unsigned int i) const;

		unsigned int size(void) const;

		class outOfRange : public std::exception {
			public:
				const char *what(void) const throw();
		};
};

#endif
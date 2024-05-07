#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define WHITE "\033[1;37m"
# define CYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[1;35m"
# define PINK "\033[95m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"


template <typename T>
void iter(T const *array, size_t len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>
void iter(T *array, size_t len, void (*f)(T &))
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>
void randonColorPrint(T const &x)
{
	static int	i = 0;
	std::string color[5] = {CYAN, GREEN, YELLOW, BLUE, PURPLE};
	std::cout << color[i++] << "                            " << x << "\033[0m" << std::endl;
	if (i == 5)
		i = 0;
}

template <typename T>
void randonColorPrint(T &x)
{
	static int	i = 0;
	std::string color[5] = {PURPLE, PURPLE, PURPLE, PURPLE, PURPLE};
	std::cout << color[i++] << "                            " << x << "\033[0m" << std::endl;
	if (i == 5)
		i = 0;
}

#endif
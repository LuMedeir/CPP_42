#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <limits.h>
# include <cstdlib>
# include <iomanip>
# include <deque> 
# include <list>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define WHITE "\033[1;37m"
# define CYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[1;35m"
# define PINK "\033[95m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"

class PmergeMe{
	private:
		std::deque<int> deque;
		std::list<int> list;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &that);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &that);
		bool validNumber(int argc, char **argv);

		void mergeInsertionSort(std::deque<int> &array);
		void mergeInsertionSort(std::list<int> &array);

		void sortDeque(int argc, char *argv[]);
		void sortList(int argc, char *argv[]);

		void sort(int argc, char *argv[]);
};

template<typename T>
void	printContainer(T &container, std::string str) {
	std::cout << CYAN << str << ":\t" WHITE;
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;
}

#endif
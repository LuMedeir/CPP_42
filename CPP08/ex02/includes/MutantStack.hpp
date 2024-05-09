#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <list>
# include <stack>
# include <iterator>

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
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) {};
		MutantStack(const MutantStack &copy){*this = copy;};
		~MutantStack(void) {};
		MutantStack	&operator=(const MutantStack &copy){
			if (this != &copy)
				std::stack<T>::operator=(copy);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void){
			return (this->c.begin());
		}
		iterator	end(void){
			return (this->c.end());
		}
};

#endif
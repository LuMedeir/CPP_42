#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define WHITE "\033[1;37m"
# define CYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[1;35m"
# define PINK "\033[95m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"

class Span
{
	private:
		std::vector<int>	vectorInt;
		unsigned int		size;
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &copy);
		Span &operator=(Span const &og);
		~Span(void);

		void addNumber(int number);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan(void);
		int longestSpan(void);

		class FullSpanException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif
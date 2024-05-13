#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>
# include <string>
# include <sstream>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define WHITE "\033[1;37m"
# define CYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[1;35m"
# define PINK "\033[95m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"

class RPN{
	private:
		std::stack<double> rpnItens;
		bool	isOperator(std::string item);
		bool	validNumber(std::string item);
		void	makeOperation(char op);
	public:
		RPN();
		RPN(RPN const &src);
		~RPN();
		RPN &operator=(RPN const &src);

		double	calculator(std::string argument);
		class RPNException : public std::exception
		{
			public:
				RPNException(const std::string &message);
				virtual ~RPNException() throw();
				virtual const char *what() const throw();

			private:
				std::string _message;
		};
};

#endif
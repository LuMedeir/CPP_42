#ifndef BTC_HPP
# define BTC_HPP

# include <iostream>
# include <map>
# include <algorithm>
# include <string>
# include <fstream>
# include <cstdlib>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define WHITE "\033[1;37m"
# define CYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[1;35m"
# define PINK "\033[95m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"

class BitcoinExchange{
	private:
		std::map<std::string, float>	dataBase;

		void	getDataBase(void);
		void	checkLine(std::string line);
		void	printLine(std::string date, float value);
		void	checkDate(std::string date);
		void	checkValue(std::string value);
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &that);
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &that);

		void	readInput(std::string file);

	class InvalidInputFormatException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class InputFileNotOpenException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class BadInputException : public std::exception {
		public:
			BadInputException(std::string line);
			virtual ~BadInputException(void) throw() {};
			virtual const char *what() const throw();
		private:
			std::string _error_message;
	};
	class NegativeNumberException : public std::exception {
		virtual const char *what() const throw();
	};
	class TooLargeNumberException : public std::exception {
		virtual const char *what() const throw();
	};
	class DatabaseException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

#endif
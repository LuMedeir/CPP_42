#ifndef BTC_HPP
# define BTC_HPP

# include <iostream>
# include <map>
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

class BitcoinExchange{
	private:
			std::map<std::string, double>	_data;
		std::string						_dataFile;
		std::string						_inputFile;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &that);
		~BitcoinExchange();
		BitcoinExchange operator=(BitcoinExchange const &that);
};

#endif
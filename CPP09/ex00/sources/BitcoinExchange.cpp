#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void){
	getDataBase();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
	if (this != &src)
		*this = src;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) { }

void	BitcoinExchange::getDataBase(void){
	std::ifstream file("data.csv");
	std::string line;
	std::string date;
	std::string value;

	if (!file.is_open())
		throw DatabaseException();
	std::getline(file, line);
	while (std::getline(file, line)) {
		date = line.substr(0, line.find(','));
		value = line.substr(line.find(',') + 1);
		this->dataBase[date] = std::atof(value.c_str());
	}
	file.close(); 
}

void BitcoinExchange::readInput(std::string fileName)
{
	std::ifstream	file(fileName.c_str());
	std::string		line;
	std::string		date;
	std::string		value;

	if (!file.is_open())
		throw InputFileNotOpenException();
	std::getline(file, line);
	if (line != "date | value")
		throw InvalidInputFormatException();
	while (std::getline(file, line)){
		try {
			checkLine(line);
		}
		catch(std::exception &e){
			std::cout << RED << "Error: " << e.what() << RESET << std::endl;
			continue ;
		}
		date = line.substr(0, line.find('|'));
		value = line.substr(line.find('|') + 1);
		printLine(date, std::atof(value.c_str()));
	}
}

void	BitcoinExchange::checkLine(std::string line){
	if (line.find("|") == std::string::npos) {
		throw BadInputException(line);
	}
	std::string date = line.substr(0, line.find('|'));
	std::string value = line.substr(line.find('|') + 1);
	date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
	value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
	if (!date.length() || !value.length())
		throw BadInputException(line);
	checkDate(date);
	checkValue(value);
}

void	BitcoinExchange::printLine(std::string date, float value){
	std::map<std::string, float>::iterator it = this->dataBase.find(date);
	float last_value = 0;

	if (it != this->dataBase.end()) {
		std::cout << BLUE << date << " => " << value;
		std::cout << " = " << value * it->second << RESET << std::endl;
		return ;
	}
	for (it = this->dataBase.begin(); it != this->dataBase.end(); it++) {
		if (it->first > date)
			break ;
		last_value = it->second;
	}
	std::cout << BLUE << date << " => " << value;
	std::cout << " = " << value * last_value << RESET << std::endl;
}

void	BitcoinExchange::checkDate(std::string date){
	int year = std::atoi(date.substr(0,4).c_str());
	int month = std::atoi(date.substr(5,2).c_str());
	int day = std::atoi(date.substr(8,2).c_str());
	
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		throw BadInputException(date);
	if (year < 2005 || year > 2023)
		throw BadInputException(date);
	if (month < 1 || month > 12)
		throw BadInputException(date);
	if (month == 2)
		if (day > 29)
			throw BadInputException(date);
}

void	BitcoinExchange::checkValue(std::string value){
	int	count = 0;

	for (unsigned int i = 0; i < value.size(); i++){
		if ((!isdigit(value[i]) && value[i] != '.') || count > 1)
			throw BadInputException(value);
		if (value[i] == '.')
			count++;
	}
	if (std::atof(value.c_str()) < 0)
		throw NegativeNumberException();
	else if (std::atof(value.c_str()) > 1000)
		throw TooLargeNumberException();
}

const char *BitcoinExchange::DatabaseException::what() const throw() {
	return ("data.csv cannot be opened");
}


const char *BitcoinExchange::InputFileNotOpenException::what() const throw() {
	return ("Input file cannot be opened");
}

const char *BitcoinExchange::InvalidInputFormatException::what() const throw() {
	return ("Input file format is invalid");
}

const char *BitcoinExchange::BadInputException::what() const throw() {
	return (_error_message.c_str());
}

BitcoinExchange::BadInputException::BadInputException(std::string line) {
	_error_message = "bad input => " + line;
}

const char *BitcoinExchange::NegativeNumberException::what() const throw() {
	return ("not a positive number");
}

const char *BitcoinExchange::TooLargeNumberException::what() const throw() {
	return ("too large a number");
}
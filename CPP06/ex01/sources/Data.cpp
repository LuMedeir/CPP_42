#include "../includes/Data.hpp"

Data::Data(void){};

Data::Data(std::string newString, int newNumber): string(newString), number(newNumber){};

Data::Data(Data const &that){
	*this = that;
}

Data::~Data(void){}

Data &Data::operator=(Data const &that){
	this->number = that.number;
	return(*this);
}

void	Data::setNumber(int newNumber){
	this->number = newNumber;
}

void	Data::setString(std::string newString){
	this->string = newString;
}

int	Data::getNumber(void) const{
	return(this->number);
}

std::string	Data::getString(void) const{
	return(this->string);
}
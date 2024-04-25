#include "../includes/Fixed.hpp"

Fixed::Fixed(void){
	std::cout << WHITE << "Default constructor called" << RESET << std::endl;
	fixedPtrValue = 0;
}

Fixed::Fixed(const Fixed &that){
	std::cout << WHITE << "Copy constructor called" << RESET << std::endl;
	*this = that;
}

Fixed &Fixed::operator=(const Fixed &that){
	std::cout << WHITE << "Copy assignment operator called" << RESET << std::endl;
	fixedPtrValue = that.getRawBits();
	return(*this);
}

Fixed::~Fixed(void){
	std::cout << WHITE << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const{
	std::cout << WHITE << "getRawBits member function called" << RESET << std::endl;
	return(fixedPtrValue);
}

void Fixed::setRawBits(int const raw)
{
	fixedPtrValue = raw;
}
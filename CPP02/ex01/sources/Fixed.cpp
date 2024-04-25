#include "../includes/Fixed.hpp"

Fixed::Fixed(void){
	std::cout << WHITE << "Default constructor called" << RESET << std::endl;
	fixedPtrValue = 0;
}

Fixed::Fixed(const Fixed &that){
	std::cout << WHITE << "Copy constructor called" << RESET << std::endl;
	*this = that;
}

// Converts a int to fixed point value
Fixed::Fixed(const int n){
	// n << this->_fractionalBits means n * 2^8 (8 is the number of fractional bits)
	// Exemple: 2.5 in binary is 10.1, so 2.5 * 2^8 = 640
	std::cout << WHITE << "Int constructor called" << RESET << std::endl;
	this->fixedPtrValue = n << this->fractionalBits;
}

// Converts a float to fixed point value
Fixed::Fixed(const float n){
	// roundf means round to nearest integer value
	// Exemple: 42.42f * 2^8 = 10814.56, so roundf(10814.56) = 10815
	// 10814 in binary is 10101000101110, so 42.42 in binary is 101010001.01110
	std::cout << WHITE << "Float constructor called" << RESET << std::endl;
	this->fixedPtrValue = roundf(n * (1 << this->fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &that){
	std::cout << WHITE << "Copy assignment operator called" << RESET << std::endl;
	fixedPtrValue = that.getRawBits();
	return(*this);
}

std::ostream &operator<<(std::ostream &o, const Fixed &that){
	o << that.toFloat();
	return(o);
}

Fixed::~Fixed(void){
	std::cout << WHITE << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const{
	return(fixedPtrValue);
}

void Fixed::setRawBits(int const raw)
{
	fixedPtrValue = raw;
}

float	Fixed::toFloat(void) const{
	// 1 << this->_fractionalBits means 1 * 2^8 (8 is the number of fractional bits)
	// Exemple: 1 * 2^8 = 256
	// Exemple: 10814 / 256 = 42.4219
	return((float)this->fixedPtrValue / (float)(1 << this->fractionalBits));
}

int		Fixed::toInt(void) const{
	// this->_fixedPointValue >> this->_fractionalBits 
	// means this->_fixedPointValue / 2^8 (8 is the number of fractional bits)
	// Exemple: 10814 / 256 = 42
	return(this->fixedPtrValue >> this->fractionalBits);
}
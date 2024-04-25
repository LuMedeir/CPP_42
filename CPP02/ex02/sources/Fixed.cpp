#include "../includes/Fixed.hpp"

// Default constructor
Fixed::Fixed(void){
	fixedPtrValue = 0;
}

// Copy constructor
Fixed::Fixed(const Fixed &that){
	*this = that;
}

// Constructor that converts a int to fixed point value
Fixed::Fixed(const int n){
	this->fixedPtrValue = n << this->fractionalBits;
}

// Constructor that converts a float to fixed point value
Fixed::Fixed(const float n){
	this->fixedPtrValue = roundf(n * (1 << this->fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &that){
	fixedPtrValue = that.getRawBits();
	return(*this);
}

// Destructor
Fixed::~Fixed(void){
}

// Assignation operator overload
std::ostream &operator<<(std::ostream &oStream, const Fixed &that){
	oStream << that.toFloat();
	return(oStream);
}

// Arithmetic sum operator overload
Fixed Fixed::operator+(Fixed const &that) const{
	return (Fixed(this->toFloat() + that.toFloat()));
}

// Arithmetic subtraction operator overload
Fixed Fixed::operator-(Fixed const &that) const{
	return (Fixed(this->toFloat() - that.toFloat()));
}

// Arithmetic multiplication operator overload
Fixed Fixed::operator*(Fixed const &that) const{
	return (Fixed(this->toFloat() * that.toFloat()));
}

// Arithmetic division operator overload
Fixed Fixed::operator/(Fixed const &that) const{
	return (Fixed(this->toFloat() / that.toFloat()));
}

// Comparison bigger than operator overload
bool Fixed::operator>(Fixed const &that) const {
	return(this->fixedPtrValue > that.getRawBits());
}

// Comparison smaller than operator overload
bool Fixed::operator<(Fixed const &that) const {
	return(this->fixedPtrValue < that.getRawBits());
}

// Comparison bigger or equal than operator overload
bool Fixed::operator>=(Fixed const &that) const {
	return(this->fixedPtrValue >= that.getRawBits());
}
// Comparison smaller or equal than operator overload
bool Fixed::operator<=(Fixed const &that) const {
	return(this->fixedPtrValue <= that.getRawBits());
}

// Comparison equal operator overload
bool Fixed::operator==(Fixed const &that) const {
	return(this->fixedPtrValue == that.getRawBits());
}

// Comparison different operator overload
bool Fixed::operator!=(Fixed const &that) const {
	return(this->fixedPtrValue != that.getRawBits());
}

// Pre-increment operator overload
Fixed &Fixed::operator++(void){
	this->fixedPtrValue++;
	return(*this);
}

// Pre-decrement operator overload
Fixed &Fixed::operator--(void){
	this->fixedPtrValue--;
	return(*this);
}

// Post-increment operator overload
Fixed Fixed::operator++(int){
	Fixed temp(*this);
	operator++();
	return(temp);
}

// Post-decrement operator overload
Fixed Fixed::operator--(int){
	Fixed temp(*this);
	operator--();
	return(temp);
}

// Convert to float
float	Fixed::toFloat(void) const{
	return((float)this->fixedPtrValue / (float)(1 << this->fractionalBits));
}

// Convert to int
int		Fixed::toInt(void) const{
	return(this->fixedPtrValue >> this->fractionalBits);
}

// Min funcion
Fixed &Fixed::min(Fixed &a, Fixed &b){
	return(a < b ? a : b);
}

// Max funcion
Fixed &Fixed::max(Fixed &a, Fixed &b){
	return(a > b ? a : b);
}

// Min funcion const
Fixed const &Fixed::min(const Fixed &a, const Fixed &b){
	return(a < b ? a : b);
}

// Max funcion const
Fixed const &Fixed::max(const Fixed &a, const Fixed &b){
	return(a > b ? a : b);
}

// Getter
int Fixed::getRawBits(void) const{
	return(fixedPtrValue);
}

// Setter
void Fixed::setRawBits(int const raw)
{
	fixedPtrValue = raw;
}
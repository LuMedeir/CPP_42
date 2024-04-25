#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include "Defines.hpp"

class Fixed{
	private:
		int	fixedPtrValue;
		static const int	fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &that);
		~Fixed(void);

		Fixed &operator=(const Fixed &that);
		Fixed operator+(const Fixed &that) const;
		Fixed operator-(const Fixed &that) const;
		Fixed operator*(const Fixed &that) const;
		Fixed operator/(const Fixed &that) const;

		bool operator==(const Fixed &that) const;
		bool operator<=(const Fixed &that) const;
		bool operator>=(const Fixed &that) const;
		bool operator!=(const Fixed &that) const;
		bool operator<(const Fixed &that) const;
		bool operator>(const Fixed &that) const;

		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		float	toFloat(void) const;
		int		toInt(void) const;

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &min(const Fixed &a, const Fixed &b);
		static Fixed const &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &o, const Fixed &that);

#endif
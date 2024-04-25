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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, const Fixed &that);

#endif
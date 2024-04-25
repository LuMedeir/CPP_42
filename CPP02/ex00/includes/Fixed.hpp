#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include "Defines.hpp"

class Fixed{
	private:
		int	fixedPtrValue;
		static const int	fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &that);
		~Fixed(void);
		Fixed &operator=(const Fixed &that);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
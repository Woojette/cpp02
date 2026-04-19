#ifndef	FIXED_HPP
# define	FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int								RawBits;
		static const int	FractionalBits = 8;
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed& other);
		~Fixed();
		Fixed&	operator=(const Fixed& other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif

#ifndef	FIXED_HPP
# define	FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					RawBits;
		static const int	FractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed&	operator=(const Fixed& other);
		int		getRawBits(void) const;
		// not change des contents of class

		void	setRawBits(int const raw);
};

#endif

// Fixed test;

// Fixed test2 = test;
// Fixed test3(test);
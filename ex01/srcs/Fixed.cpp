#include "Fixed.hpp"

Fixed::Fixed()
	: RawBits (0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
  this->RawBits = n * 256;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
	this->RawBits = roundf(f * (1 << FractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->RawBits = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->RawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->RawBits = raw;
}

float   Fixed::toFloat(void) const
{
	return ((float)RawBits / (1 << FractionalBits));
}

int     Fixed::toInt(void) const
{
	return (RawBits >> FractionalBits);
}

std::ostream&   operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}

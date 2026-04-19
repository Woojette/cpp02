#include "Fixed.hpp"

Fixed::Fixed()
	: RawBits (0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
  this->RawBits = n << FractionalBits;
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

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->RawBits > other.RawBits);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->RawBits < other.RawBits);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->RawBits >= other.RawBits);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->RawBits <= other.RawBits);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->RawBits == other.RawBits);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->RawBits != other.RawBits);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed&	Fixed::operator++()
{
	this->RawBits++;
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	Fixed temp(*this);
	this->RawBits++;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	this->RawBits--;
	return (*this);
}

Fixed		Fixed::operator--(int)
{
	Fixed temp(*this);
	this->RawBits--;
	return (temp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const	Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const	Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream&   operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}

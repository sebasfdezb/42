/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:17:27 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/24 20:18:41 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixedPointValue = 0;
}

Fixed::Fixed(const int n)
{
	_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float n)
{
	_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed &assign)
{
	if (this != &assign)
		this->_fixedPointValue = assign.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits())  / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}

bool Fixed::operator>(const Fixed other) const
{
	return	getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed other) const
{
	return	getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed other) const
{
	return	getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed other) const
{
	return	getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed other) const
{
	return	getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed other) const
{
	return	getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	_fixedPointValue += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_fixedPointValue += 1;
	return (tmp);
}

Fixed &Fixed::operator--()
{
	_fixedPointValue -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_fixedPointValue -= 1;
	return (tmp);
}

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
	return x.getRawBits() < y.getRawBits() ? x : y;
}

const Fixed &Fixed::min(const Fixed &x, const Fixed &y)
{
	return x.getRawBits() < y.getRawBits() ? x : y;
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
	return x.getRawBits() > y.getRawBits() ? x : y;
}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y)
{
	return x.getRawBits() > y.getRawBits() ? x : y;
}
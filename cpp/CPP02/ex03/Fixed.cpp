/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:17:27 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/25 18:54:47 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int n)
{
	this->_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float n)
{
	this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &original)
{
	this->_fixedPointValue = original.getRawBits();
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedPointValue)  / (1 << this->_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}

bool Fixed::operator>(const Fixed &other)
{
	if (other._fixedPointValue > this->_fixedPointValue)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &other)
{
	if (other._fixedPointValue < this->_fixedPointValue)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &other)
{
	if (other._fixedPointValue >= this->_fixedPointValue)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other)
{
	if (other._fixedPointValue <= this->_fixedPointValue)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &other)
{
	if (other._fixedPointValue == this->_fixedPointValue)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other)
{
	if (other._fixedPointValue != this->_fixedPointValue)
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &other)
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other)
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other)
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other)
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue++;
	return (tmp);
}

Fixed &Fixed::operator--()
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue--;
	return (tmp);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	return (second);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	return (second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
}
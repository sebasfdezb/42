/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:07:29 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/24 20:13:56 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP
# define	FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		int	getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;

	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &copy);
	~Fixed();
		
	Fixed &operator=(const Fixed &assing);
	
	bool operator>(const Fixed operation) const;
	bool operator<(const Fixed operation) const;
	bool operator>=(const Fixed operation) const;
	bool operator<=(const Fixed operation) const;
	bool operator==(const Fixed operation) const;
	bool operator!=(const Fixed operation) const;

	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;
	
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	static Fixed &min(Fixed &x, Fixed &y);
	static const Fixed &min(const Fixed &x, const Fixed &y);
	static Fixed &max(Fixed &x, Fixed &y);
	static const Fixed &max(const Fixed &x, const Fixed &y);
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
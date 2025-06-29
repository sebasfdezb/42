/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:07:29 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/24 19:46:40 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP
# define	FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &rhs);
		Fixed& operator = (const Fixed &rhs);
		~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);\
	float	toFloat(void) const;
	int		toInt(void) const;	
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
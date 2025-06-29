/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:07:29 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/23 20:14:52 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP
# define	FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 0;
	public:
		Fixed();
		Fixed(const Fixed &rhs);
		Fixed& operator = (const Fixed &rhs);
		~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);	
};

#endif
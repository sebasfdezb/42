/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:13:43 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/25 18:59:01 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		const	Fixed x;
		const	Fixed y;
	public:
		Point();
		Point(const Point &other);
		Point(const float nbr, const float nbr2);
		Point(Fixed const x, Fixed const y);
		~Point();
		Point &operator = (const Point &other);
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp(Point const a,Point const b, Point const c, Point const point);

#endif
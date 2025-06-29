/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:21:26 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/25 18:57:58 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():x(0), y(0)
{
}

Point::Point(const float nbr, const float nbr2): x(nbr), y(nbr2)
{
}

Point::Point(const Point &other): x(other.x), y(other.y)
{
}

Point::Point(Fixed x, Fixed y): x(x), y(y)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:27:26 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/25 18:35:43 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	len1, len2;
	Point	d(b.getX() - a.getX(), b.getY() - a.getY());
	Point	e(c.getX() - a.getX(), c.getY() - a.getY());

	len1 = (e.getX() * (a.getY() - point.getY()) + e.getY() * (point.getX() - a.getX())) / (d.getX() * e.getY() - d.getY() - e.getX());
	len2 = (point.getY() - a.getY() - len1 * d.getY()) / e.getY();
	if (len1.toFloat() >= 0.0f && len2.toFloat() >= 0.0f && (len1.toFloat() + len2.toFloat()) <= 1.0f)
		return (true);
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:01:11 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/25 18:59:45 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) 
{
	Point	const a(0, 0);
	Point	const b(1, 1);
	Point	const c(2, 4);
	Point	const point(2, 2);

	if (bsp(a, b, c, point))
		std::cout << "The point is inside the triangule" << std::endl;
	else
		std::cout << "The point is not inside the triangule" << std::endl;
	return 0;
}
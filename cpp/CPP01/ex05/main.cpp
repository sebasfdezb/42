/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:49:24 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/04 20:21:23 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	std::string input;
	Harl		harl;
	
	while (true)
	{
		std::cout << "Enter a level: ";
		if (!(std::cin >> input))
		{
			std::cout << std::endl;
			break ;
		}
		harl.complain(input);
		if (input == "exit")
			break ;
	}
	return (EXIT_SUCCESS);
}

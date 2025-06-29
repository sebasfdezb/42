/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:49:24 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 20:47:37 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	std::string level = argv[1];
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	if (argc != 2)
	{
		std::cout << "Error: incorrect argument" << std::endl;
		return (EXIT_FAILURE);
	}
	while (i < 4 && levels[i] != level)
		i++;
	switch (i)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:49:24 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/04 20:25:44 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		return (EXIT_FAILURE);
	}

	std::string level = argv[1];
	Harl harl;

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4 && levels[i] != level)
		i++;

	switch (i)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			[[fallthrough]];
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			[[fallthrough]];
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			[[fallthrough]];
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:07:01 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 20:20:56 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string	file = argv[1];
		std::string	s1 = argv[2];
		std::string s2 = argv[3];
		if (s1.empty())
		{
			std::cout << "Error: the string s1 can't be empty\n";
			return (1);
		}
		if (Replace::replace(file, s1, s2) == 1)
			return (1);
	}
	else
	{
		std::cout << "Error: incorrect number of arguments\n";
		return (1);
	}
	return (0);
}
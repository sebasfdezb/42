/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:07:01 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/04 19:29:13 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./Replace <filename> <to_find> <replace>." << std::endl;
		return (EXIT_FAILURE);
	}
	else
	{
		Replace replace(argv[1]);
		replace.replace(argv[2], argv[3]);
	}
	return (EXIT_SUCCESS);
}

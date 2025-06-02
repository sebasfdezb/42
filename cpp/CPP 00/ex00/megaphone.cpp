/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:55:06 by sebferna          #+#    #+#             */
/*   Updated: 2024/12/16 14:29:46 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int	i;
	int	j;
	i = 0;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (std::isalpha(argv[i][j]))
			{
				std::cout << (char)std::toupper(argv[i][j]);
			}
			else
			{
				std::cout << (argv[i][j]);
			}
			j++;
		}
	}
	std::cout << std::endl;
}

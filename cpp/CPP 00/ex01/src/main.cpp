/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:02:50 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/02 18:54:29 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"

int main()
{
	std::string	choose;
	PhoneBook	phonebook;

	while (true)
	{
		std::cout << "\nChoose an option: ADD | SEARCH | EXIT" << std::endl;
		if (!getline(std::cin, choose))
		{
			std::cout << std::endl;
			break ;
		}
		if (choose == "ADD" || choose == "add")
		{
			phonebook.addContact();
			continue;
		}
			if (choose == "SEARCH" || choose == "search")
		{
			phonebook.searchContact();
			continue;
		}
		if (choose == "EXIT" || choose == "exit")
			break ;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
			std::cout << "\nTry again" << std::endl;
		}
	}
	return (0);
}
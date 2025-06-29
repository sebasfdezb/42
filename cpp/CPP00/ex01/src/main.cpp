/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:02:50 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 18:37:48 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"

int main()
{
	std::string	input;
	PhoneBook	agenda;

	while (true)
	{
		std::cout << "\ninput an option: ADD | SEARCH | EXIT\nOption: " << std::endl;
		if (!getline(std::cin, input))
		{
			std::cout << std::endl;
			break ;
		}
		if (input == "ADD" || input == "add")
		{
			agenda.addContact();
			continue;
		}
		if (input == "SEARCH" || input == "search")
		{
			agenda.searchContact();
			continue;
		}
		if (input == "EXIT" || input == "exit")
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
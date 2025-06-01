/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:42:52 by sebferna          #+#    #+#             */
/*   Updated: 2025/05/19 22:12:27 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Phonebook.hpp"

int	Phonebook::index = 0;

std::string	getInput(std::string str)
{
	std::string	input;

	while (input.empty())
	{
		std::cout << str;
		if (!getline(std::cin, input))
		{
			std::cout << std::endl;
			exit(0);
		}
	}
	return (input);
}

void	Phonebook::addContact()
{
	int	i;

	i = 0;

	if (index > 7)
	{
		while (i < 7)
		{
			contacts[i] = contacts[i + 1];
			i++;
		}
		index--;
	}
	contacts[index].setName(getInput("\nName: "));
	contacts[index].setLastName(getInput("\nLast Name: "));
	contacts[index].setNickname(getInput("\nNickname: "));
	contacts[index].setPhone(getInput("\nPhone: "));
	contacts[index].setDarkestSecret(getInput("\nDarkest secret: "));
	Phonebook::index++;
}

void printTable(std::string lines)
{
	if (lines.size() > 10)
		std::cout << std::setw(9) << std::right << lines.substr(0, 9) << "." << '|';
	else
		std::cout << std::setw(10) << std::right << lines << '|';
}

void Phonebook::searchContact()
{
	int					index;
	int					currIndex;
	std::string			sIndex;
	std::stringstream	str;

	currIndex = 0;

	if (Phonebook::index == 0)
	{
		std::cout << "\nAdd a contact" << std::endl;
		return ;
	}
	std::cout << "|     Index| Name|  LastName|  Nickname|" << std::endl;
	while (currIndex < Phonebook::index)
	{
		std::cout << "|" << std::setw(10) << std::right << currIndex << '|';
		printTable(contacts[currIndex].getName());
		printTable(contacts[currIndex].getLastName());
		printTable(contacts[currIndex].getNickname());
		std::cout << std::endl;
		currIndex++;
	}
	while (true)
	{
		sIndex = getInput("Index: ");
		if (sIndex.size() != 1 || !std::isdigit(sIndex[0]))
		{
			std::cout << "Try again" << std::endl;
			continue;
		}
		str << sIndex;
		str >> index;
		str.clear();
		break ;
	}
	if (index < 0 || index > Phonebook::index - 1)
		std::cout << "Out of boundaries" << std::endl;
	else
	{
		std::cout << "\nFirst Name: " << contacts[index].getName() << std::endl;
		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << contacts[index].getPhone() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;		
	}
}

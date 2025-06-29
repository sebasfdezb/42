/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:42:52 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 18:29:41 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"

int	PhoneBook::index = 0;

bool containsAlnum(const std::string& input) {
	for (size_t i = 0; i < input.length(); i++) {
		if (std::isalnum(input[i]))
			return (true);
	}
	return (false);
}

std::string	getInput(std::string str)
{
	std::string	input;

	while (input.empty() || !containsAlnum(input))
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

void	PhoneBook::addContact()
{
	int	i;
	std::string nbr;

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
	while (true)
	{
		nbr = getInput("\nName: ");
		bool valid = true;
		for (size_t j = 0; j < nbr.length(); j++)
		{
			if (!std::isalpha(nbr[j]))
			{
				valid = false;
				break;
			}
		}
		if (!nbr.empty() && valid)
			break;
	}
	contacts[index].setName(nbr);
	while (true)
	{
		nbr = getInput("\nLast Name: ");
		bool valid = true;
		for (size_t j = 0; j < nbr.length(); j++)
		{
			if (!std::isalpha(nbr[j]))
			{
				valid = false;
				break;
			}
		}
		if (!nbr.empty() && valid)
			break;
	}
	contacts[index].setLastName(nbr);
	contacts[index].setNickname(getInput("\nNickname: "));
	while (true)
	{
		nbr = getInput("\nPhone: ");
		bool valid = true;
		for (size_t j = 0; j < nbr.length(); j++)
		{
			if (!std::isdigit(nbr[j]))
			{
				valid = false;
				break;
			}
		}
		if (!nbr.empty() && valid)
			break;
	}
	contacts[index].setPhone(nbr);
	contacts[index].setDarkestSecret(getInput("\nDarkest secret: "));
	PhoneBook::index++;
}

void printTable(std::string lines)
{
	if (lines.size() > 10)
		std::cout << std::setw(9) << std::right << lines.substr(0, 9) << "." << '|';
	else
		std::cout << std::setw(10) << std::right << lines << '|';
}

void PhoneBook::searchContact()
{
	int					index;
	int					currIndex;
	std::string			sIndex;
	std::stringstream	str;

	currIndex = 0;

	if (PhoneBook::index == 0)
	{
		std::cout << "\nAdd a contact" << std::endl;
		return ;
	}
	std::cout << "|     Index| Name|  LastName|  Nickname|" << std::endl;
	while (currIndex < PhoneBook::index)
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
		if (index < 0 || index > PhoneBook::index - 1)
		{
			std::cout << "Try Again" << std::endl;
			continue;
		}
		break;
	}
	std::cout << "\nFirst Name: " << contacts[index].getName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhone() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;	
}

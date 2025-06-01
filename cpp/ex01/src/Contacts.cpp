/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:27:54 by sebferna          #+#    #+#             */
/*   Updated: 2025/05/19 20:11:14 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Contact.hpp"

void	Contact::setName(std::string str)
{
	name = str;
}

void	Contact::setLastName(std::string str)
{
	last_name = str;
}

void	Contact::setNickname(std::string str)
{
	nickname = str;
}

void	Contact::setPhone(std::string number)
{
	phone = number;
}

void	Contact::setDarkestSecret(std::string str)
{
	darkest_secret = str;
}

std::string	Contact::getName()
{
	return (name);
}

std::string	Contact::getLastName()
{
	return (last_name);
}

std::string	Contact::getNickname()
{
	return (nickname);
}

std::string	Contact::getPhone()
{
	return (phone);
}

std::string Contact::getDarkestSecret()
{
	return (darkest_secret);
}


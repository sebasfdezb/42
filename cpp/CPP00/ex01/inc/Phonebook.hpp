/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:30:39 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 19:24:12 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"

#include <sstream>
#include <iomanip>
#include <iostream>
#include <ctype.h>

class PhoneBook
{
	private:
		Contact contacts[8];
		static int index;

	public:
		void addContact();
		void searchContact();
};

#endif
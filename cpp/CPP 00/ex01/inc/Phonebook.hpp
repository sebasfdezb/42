/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:30:39 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/02 18:36:50 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"

#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <string>
#include <cstdlib>

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
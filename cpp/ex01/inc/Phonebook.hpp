/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:35:50 by sebferna          #+#    #+#             */
/*   Updated: 2025/05/19 22:10:48 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HP

# include "Contact.hpp"
# include <iomanip>
# include <cstdlib>
# include <string>
# include <cstdlib>
# include <sstream>
# include <ctype.h>

class Phonebook
{
	private:
		Contact	contacts[8];
		static int		index;
	public:
		void	addContact();
		void	searchContact();
};

#endif
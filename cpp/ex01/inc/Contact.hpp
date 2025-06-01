/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:37:21 by sebferna          #+#    #+#             */
/*   Updated: 2025/05/19 22:10:46 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HP

# include <iostream>

class Contact
{
	private:
		std::string name;
		std::string last_name;
		std::string nickname;
		std::string phone;
		std::string darkest_secret;

	public:
		void	setName(std::string str);
		void	setLastName(std::string str);
		void	setNickname(std::string str);
		void	setPhone(std::string number);
		void	setDarkestSecret(std::string secret);
		std::string getName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhone();
		std::string getDarkestSecret();
};

#endif
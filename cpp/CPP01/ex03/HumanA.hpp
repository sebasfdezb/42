/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:02:03 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/03 19:18:52 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon&		_weapon;
		HumanA();
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void	attack(void) const;
};

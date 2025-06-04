/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:19:09 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/03 19:19:19 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon*		_weapon;
	public:
		HumanB(std::string name);
		~HumanB();
	void	attack(void) const;
	void	setWeapon(Weapon& weapon);
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:13:40 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 20:11:03 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void) const
{
	if (this->_weapon.getType() != "")
		std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
	else
		std::cout << _name << " doesnt have a weapon a attack." << std::endl;
}

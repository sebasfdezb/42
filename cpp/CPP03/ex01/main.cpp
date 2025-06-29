/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:09:00 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/26 19:15:21 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	mainCharacter("tarnished");

	mainCharacter.attack("Maliketh");
	mainCharacter.takeDamage(9);
	mainCharacter.beRepaired(10);
	mainCharacter.takeDamage(1);
	mainCharacter.guardGate();
	ScavTrap co_mainCharacter = mainCharacter;
	co_mainCharacter.guardGate();
}

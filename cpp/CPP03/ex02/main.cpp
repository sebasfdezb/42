/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:09:00 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/26 19:29:10 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap	mainCharacter("Tarnished");

	mainCharacter.attack("Maliketh");
	mainCharacter.takeDamage(9);
	mainCharacter.beRepaired(10);
	mainCharacter.takeDamage(1);
	mainCharacter.highFiveGuys();
	FragTrap co_mainCharacter = mainCharacter;
	co_mainCharacter.highFiveGuys();
}

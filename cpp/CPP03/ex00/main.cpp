/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:09:00 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/25 19:23:51 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	mainCharacter("tarnished");

	mainCharacter.attack("Maliketh");
	mainCharacter.takeDamage(9);
	mainCharacter.beRepaired(10);
	mainCharacter.takeDamage(1);
}
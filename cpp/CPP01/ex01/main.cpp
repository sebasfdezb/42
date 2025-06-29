/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:00:10 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/02 20:11:15 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	*Zombie = zombieHorde(5, "Zombiee");
	Zombie[0].announce();
	Zombie[1].announce();
	Zombie[2].announce();
	Zombie[3].announce();
	Zombie[4].announce();
	delete[] (Zombie);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:00:10 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 19:52:38 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie Musashi("Musashi");
	Musashi.announce();
	Zombie *Zombie = newZombie("Foo");
	Zombie->announce();
	randomChump("BO3 Zombie");
	delete(Zombie);
}
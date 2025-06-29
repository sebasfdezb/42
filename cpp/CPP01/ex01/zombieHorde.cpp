/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:03:42 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 19:59:34 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
	int		i;
	Zombie	*ArrayZomber;
	
	i = 0;
	ArrayZomber = new Zombie[N];
	while (i < N)
	{
		ArrayZomber[i].setName(name);
		i++;
	}
	return (ArrayZomber);
}

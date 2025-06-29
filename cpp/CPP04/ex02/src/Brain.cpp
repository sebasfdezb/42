/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:20:34 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 16:25:21 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor has been called." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor has been called." << std::endl;
}

Brain::Brain(const Brain &original)
{
	std::cout << "Brain copy constructor has been called." << std::endl;
	*this = original;
}

Brain &Brain::operator=(const Brain &other)
{
	int i;
	std::cout << "Brain copy operator has been called." << std::endl;
	if (this != &other)
	{
		i = 0;
		while (i < 100)
		{
			this->idea[i] = other.idea[i];
			i++;
		}
	}
	return (*this);
}
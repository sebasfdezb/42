/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:30:24 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 15:40:08 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << type << " constructor has been called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor has been called." << std::endl;
}

Dog::Dog(const Dog &original) : Animal(original)
{
	std::cout << "Dog copy constructor has been called." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy operator has been called." << std::endl;
	if (this != &other)
		Animal::operator = (other);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}


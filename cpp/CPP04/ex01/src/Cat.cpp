/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:22:25 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 15:28:41 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << type << " constructor has been called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor has been called." << std::endl;
}

Cat::Cat(const Cat &original) : Animal(original)
{
	std::cout << "Cat copy constructor has been called." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy operator has been called." << std::endl;
	if (this != &other)
		Animal::operator= (other);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
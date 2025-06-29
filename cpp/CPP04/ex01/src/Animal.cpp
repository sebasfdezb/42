/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:08:46 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 16:32:05 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor has been called." << std::endl;
	this->type = "Default";
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal " << type << " constructor called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor has been called." << std::endl;
}

Animal::Animal(const Animal &original)
{
	std::cout << "Animal copy constructor has been called." << std::endl;
	this->type = original.type;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy operator has been called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound." << std::endl;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:51:06 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 16:12:00 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << type << " constructor has been called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor has been called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &original) : WrongAnimal(original)
{
	std::cout << "WrongCat copy constructor has been called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy operator has been called." << std::endl;
	if (this != &other)
		WrongCat::operator = (other);
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Quack!" << std::endl;
}
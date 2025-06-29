/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:27:24 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/26 19:29:21 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "Default constructor called." << std::endl;
	this->name = "Default";
	this->Hp = 100;
	std::cout << "FragTrap: Default "<< " initial Hp = " << this->Hp << std::endl;
	this->Ep = 100;
	std::cout << "FragTrap: Default "<< " initial Ep = " << this->Ep << std::endl;
	this->Ad = 30;
	std::cout << "FragTrap: Default "<< " initial Ad = " << this->Ad << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "Name constructor called." << std::endl;
	this->name = name;
	this->Hp = 100;
	std::cout << "FragTrap: "<< this->name << " initial Hp = " << this->Hp << std::endl;
	this->Ep = 100;
	std::cout << "FragTrap: "<< this->name << " initial Ep = " << this->Ep << std::endl;
	this->Ad = 30;
	std::cout << "FragTrap: "<< this->name << " initial Ad = " << this->Ad << std::endl;
}

FragTrap::FragTrap(const FragTrap& original)
{
	std::cout << "Copy constructor has been called." << std::endl;
	this->name = original.name;
	this->Hp = original.Hp;
	std::cout << "FragTrap copy: " << this->name << " initial Hp = " << this->Hp << std::endl;
	this->Ep = original.Ep;
	std::cout << "FragTrap copy: " << this->name << " initial Ep = " << this->Ep << std::endl;
	this->Ad = original.Ad;
	std::cout << "FragTrap copy: " << this->name << " initial Ad = " << this->Ad << std::endl;
}

FragTrap&	FragTrap::operator = (const FragTrap& other)
{
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->Hp = other.Hp;
		this->Ep = other.Ep;
		this->Ad = other.Ad;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap named: " << this->name << " has been destroyed." << std::endl;
}

void	FragTrap::highFiveGuys(void)
{
	if (this->Hp != 0 && this->Ep != 0)
		std::cout << "FragTrap " << this->name << " is requesting to high five." << std::endl;
	if (this->Hp == 0)
		std::cout << "FragTrap " << this->name << " is dead, can't high five." << std::endl;
}

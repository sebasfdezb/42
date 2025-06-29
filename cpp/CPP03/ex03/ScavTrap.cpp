/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:02:03 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/26 19:20:24 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "Default constructor called." << std::endl;
	this->name = "Default";
	this->Hp = 10;
	std::cout << "ScavTrap: Default "<< " initial Hp = " << this->Hp << std::endl;
	this->Ep = 50;
	std::cout << "ScavTrap: Default "<< " initial Ep = " << this->Ep << std::endl;
	this->Ad = 20;
	std::cout << "ScavTrap: Default "<< " initial Ad = " << this->Ad << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "Name constructor called" << std::endl;
	this->name = name;
	this->Hp = 100;
	std::cout << "ScavTrap: " << this->name << " initial Hp = " << this->Hp << std::endl;
	this->Ep = 50;
	std::cout << "ScavTrap: " << this->name << " initial Ep = " << this->Ep << std::endl;
	this->Ad = 20;
	std::cout << "ScavTrap: " << this->name << " initial Ad = " << this->Ad << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original)
{
std::cout << "Copy constructor has been called." << std::endl;
	this->name = original.name;
	this->Hp = original.Hp;
	std::cout << "ScavTrap copy: " << this->name << " initial Hp = " << this->Hp << std::endl;
	this->Ep = original.Ep;
	std::cout << "ScavTrap copy: " << this->name << " initial Ep = " << this->Ep << std::endl;
	this->Ad = original.Ad;
	std::cout << "ScavTrap copy: " << this->name << " initial Ad = " << this->Ad << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->Hp = other.Hp;
		this->Ep = other.Ep;
		this->Ad = other.Ad;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap named: " << this->name << " has been destroyed." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->Hp && this->Ep)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->Ad << " points of damage!" << std::endl;
		this->Ep -= 1;
		return ;
	}
	if (this->Ep == 0)
		std::cout << "ScavTrap " << this->name << " don't have energy to attack." << std::endl;
	if (this->Hp == 0)
		std::cout << "ScavTrap " << this->name << " is dead, he can't attack." << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->Hp != 0 && this->Ep != 0)
		std::cout << "ScavTrap " << this->name << " is in gate keeper mode." << std::endl;
	if (this->Hp == 0)
		std::cout << "ScavTrap " << this->name << " is dead, can't guard the gate." << std::endl;
}

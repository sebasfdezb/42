/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:23:57 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/25 19:25:53 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called." << std::endl;
	this->name = "Default";
	this->Hp = 10;
	std::cout << "Claptrap: Default "<< " initial Hp = " << this->Hp << std::endl;
	this->Ep = 10;
	std::cout << "Claptrap: Default "<< " initial Ep = " << this->Ep << std::endl;
	this->Ad = 0;
	std::cout << "Claptrap: Default "<< " initial Ad = " << this->Ad << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Name constructor called" << std::endl;
	this->name = name;
	this->Hp = 10;
	std::cout << "Claptrap: " << this->name << " initial Hp = " << this->Hp << std::endl;
	this->Ep = 10;
	std::cout << "Claptrap: " << this->name << " initial Ep = " << this->Ep << std::endl;
	this->Ad = 0;
	std::cout << "Claptrap: " << this->name << " initial Ad = " << this->Ad << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& original)
{
	std::cout << "Copy constructor has been called." << std::endl;
	this->name = original.name;
	this->Hp = original.Hp;
	std::cout << "Claptrap copy: " << this->name << " initial Hp = " << this->Hp << std::endl;
	this->Ep = original.Ep;
	std::cout << "Claptrap copy: " << this->name << " initial Ep = " << this->Ep << std::endl;
	this->Ad = original.Ad;
	std::cout << "Claptrap copy: " << this->name << " initial Ad = " << this->Ad << std::endl;
}

ClapTrap&	ClapTrap::operator = (const ClapTrap& other)
{
	std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->Hp = other.Hp;
		this->Ep = other.Ep;
		this->Ad = other.Ad;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap named: " << this->name << " has been destroyed." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->Hp && this->Ep)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->Ad << " points of damage!" << std::endl;
		this->Ep -= 1;
		return ;
	}
	if (this->Ep == 0)
		std::cout << "ClapTrap " << this->name << " don't have energy to attack." << std::endl;
	if (this->Hp == 0)
		std::cout << "ClapTrap " << this->name << " is dead, he can't attack." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Hp > 0)
	{
		if (this->Hp >= (int)amount)
			this->Hp -= amount;
		else
			this->Hp -= this->Hp;
		std::cout << "ClapTrap named " << this->name << " has taken " << amount << " point of damage." << std::endl;
		return ;
	}
	if (this->Hp == 0)
		std::cout << "ClapTrap named " << this->name << " can't be attacked, he's already dead."<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Hp > 0 && this->Ep > 0)
	{
		this->Hp += amount;
		std::cout << "ClapTrap named " << this->name << " healed " << amount << " point of damage." << std::endl;
		return ;
	}
	if (this->Ep == 0)
		std::cout << "ClapTrap named " << this->name << " don't have energy to be repaired." << std::endl;
	if (this->Hp == 0)
		std::cout << "ClapTrap named " << this->name << " is dead, he can't be repaired." << std::endl;
}

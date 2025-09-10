/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:58:38 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 17:47:59 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default_ScavTrap")
{
	this->hitPoints = SCAV_HIT_POINTS;
	this->energyPoints = SCAV_ENERGY_POINTS;
	this->attackDamage = SCAV_ATTACK_DAMAGE;
	std::cout << "ScavTrap " << name << " has been created with default constructor." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->hitPoints = SCAV_HIT_POINTS;
	this->energyPoints = SCAV_ENERGY_POINTS;
	this->attackDamage = SCAV_ATTACK_DAMAGE;
	std::cout << "ScavTrap " << name << " has been created with parameterized constructor." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << name << " has been created by copy constructor." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap assignment operator called for " << name << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " has been destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " has no energy left to attack!" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}

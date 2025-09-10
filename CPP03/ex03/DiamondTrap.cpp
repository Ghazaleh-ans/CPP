/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:00:00 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 16:57:09 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), name("Default")
{
	this->hitPoints = FragTrap::hitPoints;      // Hit points from FragTrap (100)
	this->energyPoints = ScavTrap::energyPoints; // Energy points from ScavTrap (50)
	this->attackDamage = FragTrap::attackDamage; // Attack damage from FragTrap (30)
	std::cout << "DiamondTrap " << name << " has been created with default constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	this->hitPoints = FragTrap::hitPoints;      // Hit points from FragTrap (100)
	this->energyPoints = ScavTrap::energyPoints; // Energy points from ScavTrap (50)
	this->attackDamage = FragTrap::attackDamage; // Attack damage from FragTrap (30)
	std::cout << "DiamondTrap " << name << " has been created with parameterized constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	std::cout << "DiamondTrap " << name << " has been created by copy constructor." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		this->name = other.name;
	}
	std::cout << "DiamondTrap assignment operator called for " << name << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " has been destroyed." << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);  // Explicitly call ScavTrap's attack method
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}
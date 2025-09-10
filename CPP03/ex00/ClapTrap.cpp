/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:21:51 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 12:27:03 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " has been created with default constructor." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap " << name << " has been created by copy constructor." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap assignment operator called for " << name << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " has been destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left to attack!" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is already dead and cannot take more damage!" << std::endl;
		return;
	}
	if (hitPoints <= amount)
	{
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and is now dead! No hit points left!" << std::endl;
	}
	else
	{
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hitPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is dead and cannot repair itself!" << std::endl;
		return;
	}
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left to repair itself!" << std::endl;
		return;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repairs itself for " << amount << " points! New hit points: " << hitPoints << std::endl;
}

std::string ClapTrap::getName() const
{
	return name;
}

unsigned int ClapTrap::getHitPoints() const
{
	return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return attackDamage;
}

void ClapTrap::setName(const std::string &name)
{
	this->name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->attackDamage = attackDamage;
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &clapTrap)
{
	out << "ClapTrap " << clapTrap.getName() << " [HitPoints: " << clapTrap.getHitPoints()
		<< ", EnergyPoints: " << clapTrap.getEnergyPoints() << ", AttackDamage: " << clapTrap.getAttackDamage() << "]";
	return out;
}

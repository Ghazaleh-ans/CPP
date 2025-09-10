/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:00:09 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 17:51:33 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default_FragTrap")
{
	this->hitPoints = FRAG_HIT_POINTS;
	this->energyPoints = FRAG_ENERGY_POINTS;
	this->attackDamage = FRAG_ATTACK_DAMAGE;
	std::cout << "FragTrap " << name << " has been created with default constructor." << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	this->hitPoints = FRAG_HIT_POINTS;
	this->energyPoints = FRAG_ENERGY_POINTS;
	this->attackDamage = FRAG_ATTACK_DAMAGE;
	std::cout << "FragTrap " << name << " has been created with parameterized constructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << name << " has been created by copy constructor." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap assignment operator called for " << name << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has been destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " is requesting a positive high five!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "FragTrap " << this->name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "FragTrap " << this->name << " has no energy left to attack!" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "FragTrap " << this->name << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}
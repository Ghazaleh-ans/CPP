/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:00:00 by gansari           #+#    #+#             */
/*   Updated: 2025/09/15 21:03:20 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Default"), droppedCount(0)
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
	for (int i = 0; i < 100; i++)
		droppedMaterias[i] = 0;
}

Character::Character(std::string const &name) : name(name), droppedCount(0)
{
	std::cout << "Character constructor called for " << name << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
	for (int i = 0; i < 100; i++)
		droppedMaterias[i] = 0;
}

Character::Character(const Character &other) : name(other.name), droppedCount(0)
{
	std::cout << "Character copy constructor called for " << name << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = 0;
	}
	for (int i = 0; i < 100; i++)
		droppedMaterias[i] = 0;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		name = other.name;
		// Delete old inventory
		for (int i = 0; i < 4; i++)
		{
			delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = 0;
		}
	}
	std::cout << "Character assignment operator called for " << name << std::endl;
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called for " << name << std::endl;
	// Delete inventory
	for (int i = 0; i < 4; i++)
		delete inventory[i];
	// Delete dropped materias
	for (int i = 0; i < droppedCount; i++)
		delete droppedMaterias[i];
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
		
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			std::cout << name << " equipped " << m->getType() << " in slot " << i << std::endl;
			return;
		}
	}
	std::cout << name << "'s inventory is full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !inventory[idx])
		return;
		
	std::cout << name << " unequipped " << inventory[idx]->getType() << " from slot " << idx << std::endl;
	
	// Store dropped materia to avoid memory leak
	if (droppedCount < 100)
	{
		droppedMaterias[droppedCount] = inventory[idx];
		droppedCount++;
	}
	else
	{
		// If dropped array is full, delete the materia (or handle differently)
		delete inventory[idx];
	}
	
	inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || !inventory[idx])
		return;
		
	inventory[idx]->use(target);
}

void Character::displayInventory() const
{
	std::cout << name << "'s inventory:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "  Slot " << i << ": ";
		if (inventory[i])
			std::cout << inventory[i]->getType() << std::endl;
		else
			std::cout << "empty" << std::endl;
	}
}
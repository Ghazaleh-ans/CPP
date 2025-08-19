/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 23:01:32 by gansari           #+#    #+#             */
/*   Updated: 2025/08/19 23:39:49 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}

void HumanB::attack() const
{
	if (weapon)
	{
		std::cout << name << " attacks with their " << weapon->getType() << "." << std::endl;
	}
	else
	{
		std::cout << name << " has no weapon to attack with." << std::endl;
	}
}

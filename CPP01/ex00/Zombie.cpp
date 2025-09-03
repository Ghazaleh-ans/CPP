/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:53:09 by gansari           #+#    #+#             */
/*   Updated: 2025/08/19 17:37:06 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed Zombie")
{
}

Zombie::Zombie(const std::string name) : name(name)
{
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed." << std::endl;
}

void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:03:08 by gansari           #+#    #+#             */
/*   Updated: 2025/08/19 18:32:28 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cerr << "Error: Number of zombies must be greater than 0." << std::endl;
		return NULL;
	}

	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		std::stringstream num;
		num << i + 1;
		std::string number = num.str();
		horde[i].setName(name + " " + number);
	}
	return horde;
}

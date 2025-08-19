/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:06:46 by gansari           #+#    #+#             */
/*   Updated: 2025/08/19 18:35:31 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 10;
	Zombie* horde = zombieHorde(N, "Zombie");

	if (horde)
	{
		for (int i = 0; i < N; ++i)
		{
			horde[i].announce();
		}
		delete[] horde;
	}
	else
	{
		std::cerr << "Failed to create zombie horde." << std::endl;
	}

	return 0;
}
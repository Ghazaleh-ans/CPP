/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:18:04 by gansari           #+#    #+#             */
/*   Updated: 2025/08/19 17:42:41 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie zombie1("Alice");
	zombie1.announce();
	Zombie* zombie2 = newZombie("Bob");
	zombie2->announce();
	randomChump("Max");
	zombie1.announce();
	delete zombie2;
	return 0;
}
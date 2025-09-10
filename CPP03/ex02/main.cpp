/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:27:27 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 15:04:46 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavy");
	FragTrap frag("Fraggy");

	std::cout << "\n--- ClapTrap Actions ---" << std::endl;
	clap.attack("Target1");
	clap.takeDamage(20);
	clap.beRepaired(10);

	std::cout << "\n--- ScavTrap Actions ---" << std::endl;
	scav.attack("Target2");
	scav.takeDamage(30);
	scav.beRepaired(15);
	scav.guardGate();

	std::cout << "\n--- FragTrap Actions ---" << std::endl;
	frag.attack("Target3");
	frag.takeDamage(40);
	frag.beRepaired(20);
	frag.highFivesGuys();

	return 0;
}
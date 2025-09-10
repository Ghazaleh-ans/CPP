/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:27:27 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 13:03:01 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavy");

	clap.attack("a target");
	clap.takeDamage(5);
	clap.beRepaired(3);

	scav.attack("another target");
	scav.takeDamage(10);
	scav.beRepaired(5);
	scav.guardGate();

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:27:27 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 11:47:39 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap1("Clappy");
	ClapTrap clap2("Trapster");
	ClapTrap clap3("Newbie");

	clap1.setAttackDamage(5);
	clap2.setAttackDamage(1);

	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAttackDamage());

	clap2.attack(clap1.getName());
	clap1.takeDamage(clap2.getAttackDamage());

	clap1.beRepaired(4);
	clap2.beRepaired(2);

	clap2.attack(clap1.getName());
	clap1.takeDamage(clap2.getAttackDamage());
	clap2.attack(clap1.getName());
	clap1.takeDamage(clap2.getAttackDamage());
	clap2.attack(clap1.getName());
	clap1.takeDamage(clap2.getAttackDamage());
	clap2.attack(clap1.getName());
	clap1.takeDamage(clap2.getAttackDamage());
	clap1.beRepaired(10);
	clap2.setEnergyPoints(2);
	clap2.attack(clap3.getName());
	clap3.takeDamage(clap2.getAttackDamage());
	clap2.attack(clap3.getName());
	clap3.takeDamage(clap2.getAttackDamage());
	clap2.attack(clap3.getName());
	clap3.takeDamage(clap2.getAttackDamage());
	return 0;
}

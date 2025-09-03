/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:42:16 by gansari           #+#    #+#             */
/*   Updated: 2025/09/03 12:24:24 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
Use References when(HumanA):
- Object always needs the referenced item
- The relationship won't change during the object's lifetime
- You want simpler, safer syntax

Use Pointers when(HumanB):
- Object may or may not have the item (optional relationship)
- You need to reassign to different objects
- You need to represent "no object" (NULL)
*/

int main() {
	Weapon club = Weapon("crude spiked club");
	Weapon sword = Weapon("sharp sword");

	HumanA bob("Bob", club);
	bob.attack();

	club.setType("some other type of club");
	bob.attack();

	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();

	HumanB jane("Jane");
	jane.attack();
	jane.setWeapon(club);
	jane.attack();
	club.setType("another type of club");
	jane.attack();
	jane.setWeapon(sword);
	jane.attack();

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 23:00:32 by gansari           #+#    #+#             */
/*   Updated: 2025/08/19 23:28:21 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
class HumanB {
private:
	std::string name;
	Weapon *weapon;
public:
	HumanB(const std::string &name);
	~HumanB();
	void setWeapon(Weapon &weapon);
	void attack() const;
};
#endif
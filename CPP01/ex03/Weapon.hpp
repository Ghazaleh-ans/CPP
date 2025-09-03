/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:35:48 by gansari           #+#    #+#             */
/*   Updated: 2025/09/03 12:30:14 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>
#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon(const std::string &type);
	~Weapon();
	const std::string &getType() const;
	void setType(const std::string &newType);
};

#endif
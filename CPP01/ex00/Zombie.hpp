/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:48:41 by gansari           #+#    #+#             */
/*   Updated: 2025/08/19 17:37:23 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	Zombie(const std::string name);
	~Zombie();

	void announce() const;
};

Zombie* newZombie(const std::string name);
void randomChump(const std::string name);

#endif
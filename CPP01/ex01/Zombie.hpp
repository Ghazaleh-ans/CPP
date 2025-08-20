/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:48:41 by gansari           #+#    #+#             */
/*   Updated: 2025/08/19 18:25:03 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie
{
private:
	std::string _name;
	
public:
	Zombie();
	Zombie(const std::string name);
	~Zombie();

	void setName(const std::string name);
	void announce() const;
};

Zombie* zombieHorde( int N, std::string name );

#endif
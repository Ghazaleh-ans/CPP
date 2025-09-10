/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:58:30 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 17:51:03 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	static const unsigned int FRAG_HIT_POINTS = 100;
	static const unsigned int FRAG_ENERGY_POINTS = 100;
	static const unsigned int FRAG_ATTACK_DAMAGE = 30;

public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	virtual ~FragTrap();
	void highFivesGuys(void);
	virtual void attack(const std::string &target);
};
#endif
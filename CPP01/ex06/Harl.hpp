/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:30:32 by gansari           #+#    #+#             */
/*   Updated: 2025/08/20 17:50:18 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#include <string>

class Harl {
public:
	Harl();
	~Harl();
	void complain(const std::string &level);
private:
	void debug();
	void info();
	void warning();
	void error();
};
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:37:22 by gansari           #+#    #+#             */
/*   Updated: 2026/02/11 14:37:49 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <string>

struct Data {
	// Member variables
	std::string	name;
	int			age;
	bool		hasPet;
	std::string	petName;
	// Constructors for easy initialization
	Data();
	Data(const std::string& n, int a, bool pet, const std::string& pName);
};

#endif
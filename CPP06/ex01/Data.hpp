/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:37:22 by gansari           #+#    #+#             */
/*   Updated: 2026/04/20 17:07:10 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <string>

struct Data {
	std::string	name;
	int			age;
	bool		hasPet;
	std::string	petName;

	Data();
	Data(const std::string& n, int a, bool pet, const std::string& pName);
};

#endif
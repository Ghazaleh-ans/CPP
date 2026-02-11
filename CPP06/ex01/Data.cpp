/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:37:47 by gansari           #+#    #+#             */
/*   Updated: 2026/02/11 14:37:52 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : name(""), age(0), hasPet(false), petName("No pet") {
}

Data::Data(const std::string& n, int a, bool pet, const std::string& pName)
	: name(n), age(a), hasPet(pet), petName(pName) {
	if (petName.empty() || (!pet && petName.empty())) {
		petName = "No pet";
	}
}
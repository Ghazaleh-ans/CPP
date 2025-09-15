/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:00:00 by gansari           #+#    #+#             */
/*   Updated: 2025/09/15 20:59:58 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria constructor called for type: " << type << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
	std::cout << "AMateria copy constructor called for type: " << type << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	// Note: We don't copy the type during assignment as mentioned in the exercise
	(void)other; // Avoid unused parameter warning
	std::cout << "AMateria assignment operator called" << std::endl;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called for type: " << type << std::endl;
}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria " << type << " used on " << target.getName() << std::endl;
}
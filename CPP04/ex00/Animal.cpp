/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:35:32 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 21:51:10 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Default")
{
	std::cout << "Animal " << type << " has been created with default constructor." << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
	std::cout << "Animal " << type << " has been created with parameterized constructor." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Animal assignment operator called for " << type << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal " << type << " has been destroyed." << std::endl;
}

void Animal::setType(std::string &type)
{
	this->type = type;
}

void Animal::getType() const
{
	return this->type;
}
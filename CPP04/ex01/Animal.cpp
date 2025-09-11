/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:35:32 by gansari           #+#    #+#             */
/*   Updated: 2025/09/11 10:31:07 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
	std::cout << "Animal parameterized constructor called for " << type << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copy constructor called for " << type << std::endl;
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
	std::cout << "Animal destructor called for " << type << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal makes some generic sound" << std::endl;
}

void Animal::setType(const std::string &type)
{
	this->type = type;
}

std::string Animal::getType() const
{
	return this->type;
}
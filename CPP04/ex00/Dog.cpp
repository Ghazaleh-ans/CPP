/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:20:00 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 23:20:00 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog " << type << " has been created with default constructor." << std::endl;
}

Dog::Dog(const std::string &type) : Animal("Dog")
{
	std::cout << "Dog " << type << " has been created with parameterized constructor." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if(this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Dog assignment operator called for " << type << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog " << type << " has been destroyed." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog says Woof Woof" << std::endl;
}
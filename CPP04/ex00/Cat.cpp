/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:40:12 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 22:58:25 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat " << type << " has been created with default constructor." << std::endl;
}

Cat::Cat(const std::string &type) : Animal("Cat")
{
	std::cout << "Cat " << type << " has been created with parameterized constructor." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if(this != other)
	{
		Animal::operator=(other);
	}
	std::cout << "Cat assignment operator called for " << type << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat " << type << " has been destroyed." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat says Mew Mew" << std::endl;
}
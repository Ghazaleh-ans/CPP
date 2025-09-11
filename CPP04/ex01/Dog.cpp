/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:20:00 by gansari           #+#    #+#             */
/*   Updated: 2025/09/11 12:20:20 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*other.brain);  // Deep copy of brain
}

Dog &Dog::operator=(const Dog &other)
{
	if(this != &other)
	{
		Animal::operator=(other);
		delete brain;  // Delete old brain
		brain = new Brain(*other.brain);  // Deep copy of new brain
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
	if (brain)
	{
		brain->setIdea(index, idea);
	}
	else
	{
		std::cout << "Dog: ERROR - brain pointer is NULL!" << std::endl;
	}
}

std::string Dog::getIdea(int index) const
{
	if (brain)
		return brain->getIdea(index);
	return "";
}

void Dog::printIdeas() const
{
	if (brain)
	{
		std::cout << "Dog's ideas:" << std::endl;
		brain->printIdeas();
	}
}
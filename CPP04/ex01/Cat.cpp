/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:40:12 by gansari           #+#    #+#             */
/*   Updated: 2025/09/11 12:23:18 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*other.brain);  // Deep copy of brain
}

Cat &Cat::operator=(const Cat &other)
{
	if(this != &other)
	{
		Animal::operator=(other);
		delete brain;  // Delete old brain
		brain = new Brain(*other.brain);  // Deep copy of new brain
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
	if (brain)
		brain->setIdea(index, idea);
	else
		std::cout << "Cat: ERROR - brain pointer is NULL!" << std::endl;
}

std::string Cat::getIdea(int index) const
{
	if (brain)
		return brain->getIdea(index);
	return "";
}

void Cat::printIdeas() const
{
	if (brain)
	{
		std::cout << "Cat's ideas:" << std::endl;
		brain->printIdeas();
	}
}
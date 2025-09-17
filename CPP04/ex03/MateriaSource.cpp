/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:00:00 by gansari           #+#    #+#             */
/*   Updated: 2025/09/17 19:50:02 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.templates[i])
			templates[i] = other.templates[i]->clone();
		else
			templates[i] = 0;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete templates[i];
			if (other.templates[i])
				templates[i] = other.templates[i]->clone();
			else
				templates[i] = 0;
		}
	}
	std::cout << "MateriaSource assignment operator called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete templates[i];
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
	{
		std::cout << "Error: MateriaSource cannot learn null materia" << std::endl;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (!templates[i])
		{
			templates[i] = materia->clone();
			std::cout << "MateriaSource learned " << materia->getType() << std::endl;
			delete materia;
			return;
		}
	}
	std::cout << "MateriaSource cannot learn more materias, templates full" << std::endl;
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] && templates[i]->getType() == type)
		{
			std::cout << "MateriaSource creating " << type << std::endl;
			return templates[i]->clone();
		}
	}
	std::cout << "MateriaSource cannot create " << type << " (unknown type)" << std::endl;
	return 0;
}
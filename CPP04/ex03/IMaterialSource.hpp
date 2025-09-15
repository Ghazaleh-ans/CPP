/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMaterialSource.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:00:00 by gansari           #+#    #+#             */
/*   Updated: 2025/09/15 21:03:51 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP
#include <string>

class AMateria;

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const &type) = 0;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:37:26 by gansari           #+#    #+#             */
/*   Updated: 2025/09/12 14:44:01 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "iostream"
#include "string"

class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	AMateria(std::string const &type);
	std::string const &getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	
	~AMateria();
};

#endif
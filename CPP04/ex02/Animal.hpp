/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:27:45 by gansari           #+#    #+#             */
/*   Updated: 2025/09/11 13:09:13 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;
	Animal();
	Animal(const std::string &type);
	Animal(const Animal &other);

public:
	Animal &operator=(const Animal &other);
	virtual ~Animal();
	virtual void makeSound() const = 0;
	virtual void setType(const std::string &type);
	virtual std::string getType() const;
};

#endif
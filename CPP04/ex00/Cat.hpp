/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:14:58 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 22:42:54 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : virtual public Animal
{
public:
	Cat();
	Cat(const std::string &type);
	Cat &operator=(const Cat &other);
	~Cat();
	void makeSound() const;
}

#endif
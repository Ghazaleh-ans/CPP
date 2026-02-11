/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:43:25 by gansari           #+#    #+#             */
/*   Updated: 2026/02/11 16:47:39 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>  // For rand()
#include <ctime>    // For time()
#include <exception>

Base*	generate(void)
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	int	random = std::rand() % 3;
	switch (random)
	{
		case 0:
			std::cout << "Generated: A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated: B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated: C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base* p)
{
	if (!p)
	{
		std::cout << "Error: NULL pointer" << std::endl;
		return;
	}
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
		return;
	}
	std::cout << "Unknown type" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception&)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception&)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception&)
	{
	}
	std::cout << "Unknown type" << std::endl;
}
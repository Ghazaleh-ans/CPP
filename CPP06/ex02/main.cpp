/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:47:47 by gansari           #+#    #+#             */
/*   Updated: 2026/02/11 17:01:20 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\n=== Test 1: Random Generation (10 objects) ===" << std::endl;
	Base*	objects[10];
	// Generate 10 random objects
	for (int i = 0; i < 10; i++)
	{
		std::cout << "\nObject " << i + 1 << ": ";
		objects[i] = generate();
	}

	std::cout << "\n=== Test 2: Identify Using Pointers ===" << std::endl;
	std::cout << "\nIdentifying all 10 objects using pointer version:\n" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Object " << i + 1 << " is: ";
		identify(objects[i]);  // Calls identify(Base* p)
	}

	std::cout << "\n=== Test 3: Identify Using References ===" << std::endl;
	std::cout << "\nIdentifying all 10 objects using reference version:\n" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Object " << i + 1 << " is: ";
		identify(*objects[i]);  // Dereference pointer to get reference
								// Calls identify(Base& p)
	}

	std::cout << "\n=== Test 4: Edge Case - NULL Pointer ===" << std::endl;
	std::cout << "\nTrying to identify NULL pointer:" << std::endl;
	Base* nullPtr = NULL;
	identify(nullPtr);  // Should handle gracefully
	
	std::cout << "\n=== Memory Cleanup ===" << std::endl;
	std::cout << "\nCleaning up all dynamically allocated objects..." << std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete objects[i];
		objects[i] = NULL;
	}
	std::cout << "All objects deleted successfully!" << std::endl;

	std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
	return 0;
}
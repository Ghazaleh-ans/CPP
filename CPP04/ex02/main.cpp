/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:00:00 by gansari           #+#    #+#             */
/*   Updated: 2025/09/11 13:10:01 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "=== Exercise 02: Abstract Class ===" << std::endl;
	
	// This should NOT compile if Animal is properly abstract:
	// Animal* animal = new Animal(); // Compilation error!
	
	std::cout << "\n--- Testing abstract class with polymorphism ---" << std::endl;
	// This should work fine - creating derived objects through base pointers
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "\nTesting sounds:" << std::endl;
	std::cout << j->getType() << " says: ";
	j->makeSound();
	std::cout << i->getType() << " says: ";
	i->makeSound();
	
	std::cout << "\nDeleting objects:" << std::endl;
	delete j;
	delete i;
	
	std::cout << "\n--- Testing array of abstract base pointers ---" << std::endl;
	const int arraySize = 4;
	Animal* animals[arraySize];
	
	// Fill with Dogs and Cats
	for (int idx = 0; idx < arraySize / 2; idx++)
	{
		animals[idx] = new Dog();
	}
	
	for (int idx = arraySize / 2; idx < arraySize; idx++)
	{
		animals[idx] = new Cat();
	}
	
	std::cout << "\nTesting sounds from array:" << std::endl;
	for (int idx = 0; idx < arraySize; idx++)
	{
		std::cout << "Animal " << idx << " (" << animals[idx]->getType() << "): ";
		animals[idx]->makeSound();
	}
	
	std::cout << "\nDeleting array:" << std::endl;
	for (int idx = 0; idx < arraySize; idx++)
	{
		delete animals[idx];
	}
	
	std::cout << "\n=== Abstract class test completed ===" << std::endl;
	return 0;
}
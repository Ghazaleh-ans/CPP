/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:00:00 by gansari           #+#    #+#             */
/*   Updated: 2025/09/11 12:16:15 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "=== Exercise 01: Brain Implementation ===" << std::endl;
	
	// Test basic functionality as required by exercise
	std::cout << "\n--- Basic test from exercise ---" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j; // should not create a leak
	delete i;
	
	std::cout << "\n--- Array of Animals test ---" << std::endl;
	// Create array of Animal objects - half Dogs, half Cats
	const int arraySize = 6;
	Animal* animals[arraySize];
	
	// Fill first half with Dogs
	for (int idx = 0; idx < arraySize / 2; idx++)
	{
		std::cout << "Creating Dog " << idx << std::endl;
		animals[idx] = new Dog();
	}
	
	// Fill second half with Cats
	for (int idx = arraySize / 2; idx < arraySize; idx++)
	{
		std::cout << "Creating Cat " << idx << std::endl;
		animals[idx] = new Cat();
	}
	
	std::cout << "\nTesting sounds from array:" << std::endl;
	for (int idx = 0; idx < arraySize; idx++)
	{
		std::cout << "Animal " << idx << " (" << animals[idx]->getType() << "): ";
		animals[idx]->makeSound();
	}
	
	std::cout << "\nDeleting animals array:" << std::endl;
	// Delete all animals (destructors must be called in correct order)
	for (int idx = 0; idx < arraySize; idx++)
	{
		std::cout << "Deleting animal " << idx << std::endl;
		delete animals[idx];
	}
	
	std::cout << "\n--- Deep Copy Testing ---" << std::endl;
	
	// Test deep copy with Dogs
	std::cout << "\nCreating original dog and setting ideas:" << std::endl;
	Dog* originalDog = new Dog();
	originalDog->setIdea(0, "I want to chase cats");
	originalDog->setIdea(1, "I love bones");
	originalDog->setIdea(2, "Walks are awesome");
	
	std::cout << "\nOriginal dog ideas:" << std::endl;
	originalDog->printIdeas();
	
	std::cout << "\nTesting copy constructor (deep copy):" << std::endl;
	Dog* copyDog = new Dog(*originalDog);
	
	std::cout << "\nCopy dog ideas (should be same):" << std::endl;
	copyDog->printIdeas();
	
	std::cout << "\nModifying original dog's ideas:" << std::endl;
	originalDog->setIdea(0, "I changed my mind about cats");
	originalDog->setIdea(3, "New idea!");
	
	std::cout << "\nOriginal dog ideas after modification:" << std::endl;
	originalDog->printIdeas();
	
	std::cout << "\nCopy dog ideas (should be unchanged - proving deep copy):" << std::endl;
	copyDog->printIdeas();
	
	// Test assignment operator
	std::cout << "\nTesting assignment operator:" << std::endl;
	Dog* assignedDog = new Dog();
	assignedDog->setIdea(0, "I'm about to be overwritten");
	
	std::cout << "Before assignment:" << std::endl;
	assignedDog->printIdeas();
	
	*assignedDog = *originalDog;  // Deep copy assignment
	
	std::cout << "After assignment (should match original):" << std::endl;
	assignedDog->printIdeas();
	
	// Modify original to prove deep copy
	originalDog->setIdea(4, "Another new idea");
	std::cout << "\nAfter modifying original again:" << std::endl;
	std::cout << "Original:" << std::endl;
	originalDog->printIdeas();
	std::cout << "Assigned (should not have new idea):" << std::endl;
	assignedDog->printIdeas();
	
	// Test with Cats too
	std::cout << "\n--- Cat Deep Copy Testing ---" << std::endl;
	Cat* originalCat = new Cat();
	originalCat->setIdea(0, "I hate dogs");
	originalCat->setIdea(1, "Fish is delicious");
	originalCat->setIdea(2, "I rule this house");
	
	Cat copyConstructedCat(*originalCat);
	
	std::cout << "Original cat:" << std::endl;
	originalCat->printIdeas();
	std::cout << "Copy constructed cat:" << std::endl;
	copyConstructedCat.printIdeas();
	
	// Modify original
	originalCat->setIdea(0, "Maybe dogs aren't so bad");
	std::cout << "\nAfter modifying original cat:" << std::endl;
	std::cout << "Original:" << std::endl;
	originalCat->printIdeas();
	std::cout << "Copy (should be unchanged):" << std::endl;
	copyConstructedCat.printIdeas();
	
	std::cout << "\n--- Cleanup ---" << std::endl;
	delete originalDog;
	delete copyDog;
	delete assignedDog;
	delete originalCat;
	
	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
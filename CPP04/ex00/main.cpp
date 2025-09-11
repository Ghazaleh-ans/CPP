/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:25:00 by gansari           #+#    #+#             */
/*   Updated: 2025/09/11 10:23:22 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Testing Correct Polymorphism ===" << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "\nType testing:" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	
	std::cout << "\nSound testing (should show specific sounds):" << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound(); // will output the dog sound!
	meta->makeSound(); // will output the animal sound!
	
	std::cout << "\nDeleting animals:" << std::endl;
	delete j;
	delete i;
	delete meta;
	
	std::cout << "\n=== Testing Wrong Polymorphism ===" << std::endl;
	
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << "\nWrong type testing:" << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << wrongMeta->getType() << " " << std::endl;
	
	std::cout << "\nWrong sound testing (should show WrongAnimal sound):" << std::endl;
	wrongCat->makeSound(); // will output WrongAnimal sound due to lack of virtual!
	wrongMeta->makeSound();
	
	std::cout << "\nDeleting wrong animals:" << std::endl;
	delete wrongCat;
	delete wrongMeta;
	
	std::cout << "\n=== Additional Tests ===" << std::endl;
	
	// Test copy constructor and assignment
	std::cout << "\nTesting copy constructor:" << std::endl;
	Dog originalDog;
	Dog copyDog(originalDog);
	
	std::cout << "\nTesting assignment operator:" << std::endl;
	Cat originalCat;
	Cat assignedCat;
	assignedCat = originalCat;
	
	std::cout << "\nTesting polymorphic behavior with direct objects:" << std::endl;
	Animal directAnimal;
	Dog directDog;
	Cat directCat;
	
	directAnimal.makeSound();
	directDog.makeSound();
	directCat.makeSound();
	
	return 0;
}
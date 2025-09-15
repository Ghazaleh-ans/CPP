/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:00:00 by gansari           #+#    #+#             */
/*   Updated: 2025/09/15 21:22:05 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "=== Exercise 03: Interface & recap ===" << std::endl;
	
	// Test from the exercise
	std::cout << "\n--- Required test from exercise ---" << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	
	std::cout << "\n--- Additional comprehensive tests ---" << std::endl;
	
	// Test MateriaSource learning limits
	std::cout << "\n1. Testing MateriaSource learning limits:" << std::endl;
	MateriaSource* source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	source->learnMateria(new Ice()); // Should fail - full
	
	// Test Character inventory limits
	std::cout << "\n2. Testing Character inventory limits:" << std::endl;
	Character* alice = new Character("alice");
	alice->equip(source->createMateria("ice"));
	alice->equip(source->createMateria("cure"));
	alice->equip(source->createMateria("ice"));
	alice->equip(source->createMateria("cure"));
	alice->equip(source->createMateria("ice")); // Should fail - full
	
	// Test unequip and dropped materias
	std::cout << "\n3. Testing unequip functionality:" << std::endl;
	alice->unequip(1); // Unequip cure from slot 1
	alice->equip(source->createMateria("ice")); // Should equip in slot 1
	
	// Test using non-existent materias
	std::cout << "\n4. Testing edge cases:" << std::endl;
	alice->use(10, *alice); // Invalid index
	alice->unequip(-1); // Invalid index
	alice->unequip(2);
	alice->use(2, *alice); // Empty slot
	
	// Test unknown materia type
	std::cout << "\n5. Testing unknown materia creation:" << std::endl;
	AMateria* unknown = source->createMateria("lightning");
	if (!unknown)
		std::cout << "Correctly returned null for unknown type" << std::endl;
	
	// Test deep copy of Character
	std::cout << "\n6. Testing Character deep copy:" << std::endl;
	Character original("original");
	original.equip(source->createMateria("ice"));
	original.equip(source->createMateria("cure"));
	
	Character copy(original);
	std::cout << "Original inventory:" << std::endl;
	original.displayInventory();
	std::cout << "Copy inventory:" << std::endl;
	copy.displayInventory();
	
	// Test using materias from both
	std::cout << "\nUsing materias from both characters:" << std::endl;
	Character target("target");
	original.use(0, target);
	copy.use(0, target);
	
	// Test assignment operator
	std::cout << "\n7. Testing assignment operator:" << std::endl;
	Character assigned("assigned");
	assigned.equip(source->createMateria("cure"));
	assigned = original; // Should deep copy
	std::cout << "Assigned character after assignment:" << std::endl;
	assigned.displayInventory();
	
	// Cleanup
	std::cout << "\n--- Cleanup ---" << std::endl;
	delete alice;
	delete source;
	
	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
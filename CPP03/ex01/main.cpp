/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:27:27 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 13:55:27 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void printSeparator(const std::string& title)
{
	std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

void testConstructorsAndDestructors()
{
	printSeparator("TESTING CONSTRUCTORS AND DESTRUCTORS");
	
	std::cout << "Creating ClapTrap with default constructor:" << std::endl;
	ClapTrap defaultClap;
	
	std::cout << "\nCreating ClapTrap with parameterized constructor:" << std::endl;
	ClapTrap clap("Clappy");
	
	std::cout << "\nCreating ScavTrap with default constructor:" << std::endl;
	ScavTrap defaultScav;
	
	std::cout << "\nCreating ScavTrap with parameterized constructor:" << std::endl;
	ScavTrap scav("Scavy");
	
	std::cout << "\nCopy constructor test:" << std::endl;
	ClapTrap clapCopy(clap);
	ScavTrap scavCopy(scav);
	
	std::cout << "\nAssignment operator test:" << std::endl;
	ClapTrap clapAssign;
	clapAssign = clap;
	
	ScavTrap scavAssign;
	scavAssign = scav;
	
	std::cout << "\nDestructors will be called when objects go out of scope..." << std::endl;
}

void testBasicFunctionality()
{
	printSeparator("TESTING BASIC FUNCTIONALITY");
	
	ClapTrap clap("Warrior");
	ScavTrap scav("Guardian");
	
	std::cout << "Initial states:" << std::endl;
	std::cout << clap << std::endl;
	std::cout << scav << std::endl;
	
	std::cout << "\nTesting attacks:" << std::endl;
	clap.attack("Enemy1");
	scav.attack("Enemy2");
	
	std::cout << "\nTesting damage:" << std::endl;
	clap.takeDamage(5);
	scav.takeDamage(15);
	
	std::cout << "\nTesting repair:" << std::endl;
	clap.beRepaired(3);
	scav.beRepaired(10);
	
	std::cout << "\nStates after actions:" << std::endl;
	std::cout << clap << std::endl;
	std::cout << scav << std::endl;
	
	std::cout << "\nTesting ScavTrap special ability:" << std::endl;
	scav.guardGate();
}

void testErrorConditions()
{
	printSeparator("TESTING ERROR CONDITIONS");
	
	ClapTrap weakClap("Weakling");
	ScavTrap weakScav("WeakGuard");
	
	std::cout << "Testing dead ClapTrap scenarios:" << std::endl;
	weakClap.takeDamage(15); // Should kill it (10 HP)
	weakClap.attack("target"); // Should fail - dead
	weakClap.takeDamage(5);   // Should fail - already dead
	weakClap.beRepaired(5);   // Should fail - dead
	
	std::cout << "\nTesting energy depletion:" << std::endl;
	ClapTrap tiredClap("Tired");
	// Drain all energy (10 energy points)
	for (int i = 0; i < 10; i++)
	{
		tiredClap.attack("target");
	}
	// These should fail due to no energy
	tiredClap.attack("target");
	tiredClap.beRepaired(1);
	
	std::cout << "\nTesting ScavTrap death scenarios:" << std::endl;
	weakScav.takeDamage(150); // Should kill it (100 HP)
	weakScav.attack("target"); // Should fail - dead
	weakScav.beRepaired(5);   // Should fail - dead
	weakScav.guardGate();     // This should still work as it doesn't check HP/energy
}

void testInheritanceChaining()
{
	printSeparator("TESTING INHERITANCE CONSTRUCTION/DESTRUCTION CHAINING");
	
	std::cout << "Watch the order of constructor/destructor calls:" << std::endl;
	std::cout << "\nCreating ScavTrap (should call ClapTrap constructor first):" << std::endl;
	{
		ScavTrap tempScav("ChainTest");
		std::cout << "\nScavTrap created. Now it will be destroyed..." << std::endl;
	}
	std::cout << "ScavTrap destroyed (should call ScavTrap destructor first, then ClapTrap)" << std::endl;
}

void testPolymorphicBehavior()
{
	printSeparator("TESTING POLYMORPHIC BEHAVIOR");
	
	ClapTrap clap("PolyClap");
	ScavTrap scav("PolyScav");
	
	std::cout << "ClapTrap attack:" << std::endl;
	clap.attack("target");
	
	std::cout << "\nScavTrap attack (should show different message):" << std::endl;
	scav.attack("target");
	
	std::cout << "\nScavTrap using inherited methods:" << std::endl;
	scav.takeDamage(20);
	scav.beRepaired(10);
	
	std::cout << "\nScavTrap special ability:" << std::endl;
	scav.guardGate();
}

int main()
{
	try
	{
		testConstructorsAndDestructors();
		testBasicFunctionality();
		testErrorConditions();
		testInheritanceChaining();
		testPolymorphicBehavior();
		
		printSeparator("ALL TESTS COMPLETED");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
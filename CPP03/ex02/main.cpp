/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:27:27 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 15:53:27 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void printSeparator(const std::string& title)
{
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << std::string(50, '=') << "\n" << std::endl;
}

void testConstructionDestructionChaining()
{
	printSeparator("CONSTRUCTION/DESTRUCTION CHAINING TEST");
	
	std::cout << "Creating all three types to verify constructor chaining:" << std::endl;
	std::cout << "\n1. ClapTrap creation:" << std::endl;
	ClapTrap clap("TestClap");
	
	std::cout << "\n2. ScavTrap creation (should call ClapTrap constructor first):" << std::endl;
	ScavTrap scav("TestScav");
	
	std::cout << "\n3. FragTrap creation (should call ClapTrap constructor first):" << std::endl;
	FragTrap frag("TestFrag");
	
	std::cout << "\n4. Objects going out of scope (destructors in reverse order)..." << std::endl;
}

void testInitialAttributes()
{
	printSeparator("INITIAL ATTRIBUTES VERIFICATION");
	
	ClapTrap clap("AttributeClap");
	ScavTrap scav("AttributeScav");
	FragTrap frag("AttributeFrag");
	
	std::cout << "ClapTrap attributes - HP: " << clap.getHitPoints() 
			  << ", Energy: " << clap.getEnergyPoints() 
			  << ", Attack: " << clap.getAttackDamage() << std::endl;
			  
	std::cout << "ScavTrap attributes - HP: " << scav.getHitPoints() 
			  << ", Energy: " << scav.getEnergyPoints() 
			  << ", Attack: " << scav.getAttackDamage() << std::endl;
			  
	std::cout << "FragTrap attributes - HP: " << frag.getHitPoints() 
			  << ", Energy: " << frag.getEnergyPoints() 
			  << ", Attack: " << frag.getAttackDamage() << std::endl;
			  
	std::cout << "\nExpected values:" << std::endl;
	std::cout << "ClapTrap: HP=10, Energy=10, Attack=0" << std::endl;
	std::cout << "ScavTrap: HP=100, Energy=50, Attack=20" << std::endl;
	std::cout << "FragTrap: HP=100, Energy=100, Attack=30" << std::endl;
}

void testAttackMethodOverriding()
{
	printSeparator("ATTACK METHOD OVERRIDING TEST");
	
	ClapTrap clap("AttackClap");
	ScavTrap scav("AttackScav");
	FragTrap frag("AttackFrag");
	
	std::cout << "Each class should show different attack messages:\n" << std::endl;
	
	std::cout << "ClapTrap attack:" << std::endl;
	clap.attack("enemy");
	
	std::cout << "\nScavTrap attack:" << std::endl;
	scav.attack("enemy");
	
	std::cout << "\nFragTrap attack:" << std::endl;
	frag.attack("enemy");
}

void testSpecialAbilities()
{
	printSeparator("SPECIAL ABILITIES TEST");
	
	ScavTrap scav("SpecialScav");
	FragTrap frag("SpecialFrag");
	
	std::cout << "Testing ScavTrap special ability:" << std::endl;
	scav.guardGate();
	
	std::cout << "\nTesting FragTrap special ability:" << std::endl;
	frag.highFivesGuys();
}

void testCopyConstructorsAndAssignment()
{
	printSeparator("COPY CONSTRUCTORS AND ASSIGNMENT TEST");
	
	std::cout << "Creating original objects:" << std::endl;
	ClapTrap originalClap("OriginalClap");
	ScavTrap originalScav("OriginalScav");
	FragTrap originalFrag("OriginalFrag");
	
	std::cout << "\nTesting copy constructors:" << std::endl;
	ClapTrap copiedClap(originalClap);
	ScavTrap copiedScav(originalScav);
	FragTrap copiedFrag(originalFrag);
	
	std::cout << "\nTesting assignment operators:" << std::endl;
	ClapTrap assignedClap;
	assignedClap = originalClap;
	
	ScavTrap assignedScav;
	assignedScav = originalScav;
	
	FragTrap assignedFrag;
	assignedFrag = originalFrag;
	
	std::cout << "\nVerifying copied/assigned objects work correctly:" << std::endl;
	copiedClap.attack("test");
	copiedScav.attack("test");
	copiedFrag.attack("test");
	
	assignedScav.guardGate();
	assignedFrag.highFivesGuys();
}

void testInheritedMethods()
{
	printSeparator("INHERITED METHODS TEST");
	
	ScavTrap scav("InheritScav");
	FragTrap frag("InheritFrag");
	
	std::cout << "Testing that derived classes inherit ClapTrap methods:" << std::endl;
	
	std::cout << "\nScavTrap using inherited methods:" << std::endl;
	scav.takeDamage(25);
	scav.beRepaired(10);
	
	std::cout << "\nFragTrap using inherited methods:" << std::endl;
	frag.takeDamage(35);
	frag.beRepaired(15);
}

void testErrorConditions()
{
	printSeparator("ERROR CONDITIONS TEST");
	
	std::cout << "Testing dead FragTrap scenarios:" << std::endl;
	FragTrap deadFrag("DeadFrag");
	deadFrag.takeDamage(150); // Kill it
	deadFrag.attack("target"); // Should fail
	deadFrag.beRepaired(10);  // Should fail
	deadFrag.highFivesGuys(); // Should still work
	
	std::cout << "\nTesting energy depletion on ScavTrap:" << std::endl;
	ScavTrap tiredScav("TiredScav");
	// Drain energy (50 energy points)
	for (int i = 0; i < 50; i++)
	{
		tiredScav.attack("target");
	}
	// These should fail
	tiredScav.attack("target");
	tiredScav.beRepaired(1);
	tiredScav.guardGate(); // Should still work
}

void testPolymorphicBehavior()
{
	printSeparator("POLYMORPHIC BEHAVIOR TEST");
	
	std::cout << "Testing that each class maintains its identity:" << std::endl;
	
	ClapTrap clap("PolyClap");
	ScavTrap scav("PolyScav");
	FragTrap frag("PolyFrag");
	
	// Each should call their own attack method
	std::cout << "\nCalling attack on each type:" << std::endl;
	clap.attack("target");
	scav.attack("target");
	frag.attack("target");
	
	// Verify attributes are different
	std::cout << "\nDamage values should be different:" << std::endl;
	std::cout << "ClapTrap damage: " << clap.getAttackDamage() << std::endl;
	std::cout << "ScavTrap damage: " << scav.getAttackDamage() << std::endl;
	std::cout << "FragTrap damage: " << frag.getAttackDamage() << std::endl;
}

void testDefaultConstructors()
{
	printSeparator("DEFAULT CONSTRUCTORS TEST");
	
	std::cout << "Testing default constructors for all classes:" << std::endl;
	
	std::cout << "\nClapTrap default constructor:" << std::endl;
	ClapTrap defaultClap;
	
	std::cout << "\nScavTrap default constructor:" << std::endl;
	ScavTrap defaultScav;
	
	std::cout << "\nFragTrap default constructor:" << std::endl;
	FragTrap defaultFrag;
	
	std::cout << "\nTesting default objects functionality:" << std::endl;
	defaultClap.attack("test");
	defaultScav.guardGate();
	defaultFrag.highFivesGuys();
}

int main()
{
	try
	{
		testConstructionDestructionChaining();
		testInitialAttributes();
		testAttackMethodOverriding();
		testSpecialAbilities();
		testCopyConstructorsAndAssignment();
		testInheritedMethods();
		testErrorConditions();
		testPolymorphicBehavior();
		testDefaultConstructors();
		
		printSeparator("ALL TESTS COMPLETED SUCCESSFULLY");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught during testing: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
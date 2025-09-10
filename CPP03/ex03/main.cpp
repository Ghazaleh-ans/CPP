/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:27:27 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 18:00:17 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void printSeparator(const std::string& title)
{
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << std::string(50, '=') << "\n" << std::endl;
}

void testDiamondTrapCreation()
{
	printSeparator("DIAMONDTRAP CREATION TEST");
	
	std::cout << "Creating DiamondTrap with default constructor:" << std::endl;
	DiamondTrap defaultDiamond;
	
	std::cout << "\nCreating DiamondTrap with parameterized constructor:" << std::endl;
	DiamondTrap namedDiamond("Sparkle");
	
	std::cout << "\nTesting whoAmI() method:" << std::endl;
	defaultDiamond.whoAmI();
	namedDiamond.whoAmI();
	
	std::cout << "\nDestructors will be called when going out of scope..." << std::endl;
}

void testAttributeInheritance()
{
	printSeparator("ATTRIBUTE INHERITANCE TEST");
	
	DiamondTrap diamond("Hybrid");
	
	std::cout << "DiamondTrap attributes should be:" << std::endl;
	std::cout << "- Hit Points: 100 (from FragTrap)" << std::endl;
	std::cout << "- Energy Points: 50 (from ScavTrap)" << std::endl;
	std::cout << "- Attack Damage: 30 (from FragTrap)" << std::endl;
	
	std::cout << "\nActual DiamondTrap attributes:" << std::endl;
	std::cout << "- Hit Points: " << diamond.getHitPoints() << std::endl;
	std::cout << "- Energy Points: " << diamond.getEnergyPoints() << std::endl;
	std::cout << "- Attack Damage: " << diamond.getAttackDamage() << std::endl;
}

void testMethodInheritance()
{
	printSeparator("METHOD INHERITANCE TEST");
	
	DiamondTrap diamond("MultiTalent");
	
	std::cout << "Testing attack method (should use ScavTrap's attack):" << std::endl;
	diamond.attack("target");
	
	std::cout << "\nTesting inherited methods from ClapTrap:" << std::endl;
	diamond.takeDamage(20);
	diamond.beRepaired(10);
	
	std::cout << "\nTesting ScavTrap special ability:" << std::endl;
	diamond.guardGate();
	
	std::cout << "\nTesting FragTrap special ability:" << std::endl;
	diamond.highFivesGuys();
	
	std::cout << "\nTesting DiamondTrap special ability:" << std::endl;
	diamond.whoAmI();
}

void testCopyAndAssignment()
{
	printSeparator("COPY CONSTRUCTOR AND ASSIGNMENT TEST");
	
	std::cout << "Creating original DiamondTrap:" << std::endl;
	DiamondTrap original("Original");
	original.takeDamage(10); // Modify state
	
	std::cout << "\nTesting copy constructor:" << std::endl;
	DiamondTrap copied(original);
	
	std::cout << "\nTesting assignment operator:" << std::endl;
	DiamondTrap assigned;
	assigned = original;
	
	std::cout << "\nVerifying copied objects work correctly:" << std::endl;
	std::cout << "Original: ";
	original.whoAmI();
	std::cout << "Copied: ";
	copied.whoAmI();
	std::cout << "Assigned: ";
	assigned.whoAmI();
	
	std::cout << "\nTesting methods on copied objects:" << std::endl;
	copied.attack("test1");
	assigned.attack("test2");
}

void testVirtualInheritance()
{
	printSeparator("VIRTUAL INHERITANCE VERIFICATION");
	
	std::cout << "Creating DiamondTrap to verify single ClapTrap instance:" << std::endl;
	DiamondTrap diamond("VirtualTest");
	
	std::cout << "\nDiamondTrap size information (for verification):" << std::endl;
	std::cout << "If virtual inheritance works correctly, there should be only one ClapTrap instance." << std::endl;
	
	std::cout << "\nTesting name shadowing:" << std::endl;
	diamond.whoAmI(); // Should show both DiamondTrap name and ClapTrap name
}

void testComplexScenario()
{
	printSeparator("COMPLEX SCENARIO TEST");
	
	std::cout << "Creating multiple types for comparison:" << std::endl;
	ClapTrap clap("BasicClap");
	ScavTrap scav("BasicScav");
	FragTrap frag("BasicFrag");
	DiamondTrap diamond("SuperDiamond");
	
	std::cout << "\nAttribute comparison:" << std::endl;
	std::cout << "ClapTrap - HP: " << clap.getHitPoints() 
			  << ", Energy: " << clap.getEnergyPoints() 
			  << ", Attack: " << clap.getAttackDamage() << std::endl;
	std::cout << "ScavTrap - HP: " << scav.getHitPoints() 
			  << ", Energy: " << scav.getEnergyPoints() 
			  << ", Attack: " << scav.getAttackDamage() << std::endl;
	std::cout << "FragTrap - HP: " << frag.getHitPoints() 
			  << ", Energy: " << frag.getEnergyPoints() 
			  << ", Attack: " << frag.getAttackDamage() << std::endl;
	std::cout << "DiamondTrap - HP: " << diamond.getHitPoints() 
			  << ", Energy: " << diamond.getEnergyPoints() 
			  << ", Attack: " << diamond.getAttackDamage() << std::endl;
	
	std::cout << "\nAttack method comparison:" << std::endl;
	std::cout << "ClapTrap attack: ";
	clap.attack("enemy");
	std::cout << "ScavTrap attack: ";
	scav.attack("enemy");
	std::cout << "FragTrap attack: ";
	frag.attack("enemy");
	std::cout << "DiamondTrap attack: ";
	diamond.attack("enemy");
	
	std::cout << "\nSpecial abilities test:" << std::endl;
	scav.guardGate();
	frag.highFivesGuys();
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();
}

void testErrorConditions()
{
	printSeparator("ERROR CONDITIONS TEST");
	
	DiamondTrap diamond("TestDiamond");
	
	std::cout << "Testing death scenarios:" << std::endl;
	diamond.takeDamage(150); // Should kill it
	diamond.attack("target"); // Should fail
	diamond.beRepaired(10);  // Should fail
	
	std::cout << "\nSpecial abilities should still work:" << std::endl;
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();
	
	std::cout << "\nTesting energy depletion:" << std::endl;
	DiamondTrap energyTest("EnergyTest");
	for (int i = 0; i < 50; i++) // Drain all 50 energy points
	{
		energyTest.attack("dummy");
	}
	energyTest.attack("dummy"); // Should fail
	energyTest.beRepaired(1);   // Should fail
}

int main()
{
	try
	{
		testDiamondTrapCreation();
		testAttributeInheritance();
		testMethodInheritance();
		testCopyAndAssignment();
		testVirtualInheritance();
		testComplexScenario();
		testErrorConditions();
		
		printSeparator("ALL TESTS COMPLETED SUCCESSFULLY");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
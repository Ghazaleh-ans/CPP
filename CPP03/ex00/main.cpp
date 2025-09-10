/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:27:27 by gansari           #+#    #+#             */
/*   Updated: 2025/09/10 16:11:15 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void printSeparator(const std::string& title)
{
	std::cout << "\n" << std::string(40, '=') << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << std::string(40, '=') << "\n" << std::endl;
}

void testConstructorsAndDestructors()
{
	printSeparator("CONSTRUCTORS AND DESTRUCTORS");
	
	std::cout << "Creating ClapTrap with default constructor:" << std::endl;
	ClapTrap defaultTrap;
	
	std::cout << "\nCreating ClapTrap with parameterized constructor:" << std::endl;
	ClapTrap namedTrap("Clappy");
	
	std::cout << "\nCopy constructor test:" << std::endl;
	ClapTrap copiedTrap(namedTrap);
	
	std::cout << "\nAssignment operator test:" << std::endl;
	ClapTrap assignedTrap;
	assignedTrap = namedTrap;
	
	std::cout << "\nDestructors will be called when objects go out of scope..." << std::endl;
}

void testBasicFunctionality()
{
	printSeparator("BASIC FUNCTIONALITY");
	
	ClapTrap warrior("Warrior");
	ClapTrap defender("Defender");
	
	std::cout << "Initial states:" << std::endl;
	std::cout << warrior << std::endl;
	std::cout << defender << std::endl;
	
	std::cout << "\nSetting attack damage for testing:" << std::endl;
	warrior.setAttackDamage(3);
	defender.setAttackDamage(2);
	
	std::cout << "Updated states:" << std::endl;
	std::cout << warrior << std::endl;
	std::cout << defender << std::endl;
	
	std::cout << "\nCombat simulation:" << std::endl;
	warrior.attack(defender.getName());
	defender.takeDamage(warrior.getAttackDamage());
	
	defender.attack(warrior.getName());
	warrior.takeDamage(defender.getAttackDamage());
	
	std::cout << "\nAfter first exchange:" << std::endl;
	std::cout << warrior << std::endl;
	std::cout << defender << std::endl;
	
	std::cout << "\nBoth try to repair:" << std::endl;
	warrior.beRepaired(2);
	defender.beRepaired(1);
	
	std::cout << "\nAfter repairs:" << std::endl;
	std::cout << warrior << std::endl;
	std::cout << defender << std::endl;
}

void testEnergyDepletion()
{
	printSeparator("ENERGY DEPLETION TEST");
	
	ClapTrap energyTest("EnergyTest");
	energyTest.setAttackDamage(1);
	
	std::cout << "Starting with: " << energyTest << std::endl;
	std::cout << "\nExhausting all energy through attacks:" << std::endl;
	
	// Drain all 10 energy points
	for (int i = 1; i <= 10; i++)
	{
		std::cout << "Attack " << i << ": ";
		energyTest.attack("dummy");
		std::cout << "Remaining energy: " << energyTest.getEnergyPoints() << std::endl;
	}
	
	std::cout << "\nTrying to attack with no energy:" << std::endl;
	energyTest.attack("dummy");
	
	std::cout << "\nTrying to repair with no energy:" << std::endl;
	energyTest.beRepaired(5);
}

void testDeathScenarios()
{
	printSeparator("DEATH SCENARIOS");
	
	ClapTrap victim("Victim");
	ClapTrap attacker("Attacker");
	attacker.setAttackDamage(15); // More than victim's HP
	
	std::cout << "Initial states:" << std::endl;
	std::cout << victim << std::endl;
	std::cout << attacker << std::endl;
	
	std::cout << "\nAttacker deals fatal damage:" << std::endl;
	attacker.attack(victim.getName());
	victim.takeDamage(attacker.getAttackDamage());
	
	std::cout << "\nVictim state after fatal damage:" << std::endl;
	std::cout << victim << std::endl;
	
	std::cout << "\nTrying actions on dead ClapTrap:" << std::endl;
	victim.attack("ghost");
	victim.takeDamage(5);
	victim.beRepaired(10);
}

void testEdgeCases()
{
	printSeparator("EDGE CASES");
	
	ClapTrap edge("EdgeCase");
	
	std::cout << "Testing damage equal to HP:" << std::endl;
	std::cout << "Initial: " << edge << std::endl;
	edge.takeDamage(10); // Exactly equal to starting HP
	std::cout << "After taking 10 damage: " << edge << std::endl;
	
	std::cout << "\nTesting repair on low HP ClapTrap:" << std::endl;
	ClapTrap lowHP("LowHP");
	lowHP.takeDamage(8); // Leave with 2 HP
	std::cout << "After 8 damage: " << lowHP << std::endl;
	lowHP.beRepaired(5);
	std::cout << "After repair: " << lowHP << std::endl;
	
	std::cout << "\nTesting zero damage attack:" << std::endl;
	ClapTrap pacifist("Pacifist");
	pacifist.attack("target");
	
	std::cout << "\nTesting large damage value:" << std::endl;
	ClapTrap tank("Tank");
	tank.takeDamage(1000);
	std::cout << "Tank after massive damage: " << tank << std::endl;
}

void testGettersAndSetters()
{
	printSeparator("GETTERS AND SETTERS");
	
	ClapTrap test("TestBot");
	
	std::cout << "Initial values:" << std::endl;
	std::cout << "Name: " << test.getName() << std::endl;
	std::cout << "HP: " << test.getHitPoints() << std::endl;
	std::cout << "Energy: " << test.getEnergyPoints() << std::endl;
	std::cout << "Attack: " << test.getAttackDamage() << std::endl;
	
	std::cout << "\nModifying values with setters:" << std::endl;
	test.setName("ModifiedBot");
	test.setHitPoints(50);
	test.setEnergyPoints(25);
	test.setAttackDamage(10);
	
	std::cout << "After modification:" << std::endl;
	std::cout << "Name: " << test.getName() << std::endl;
	std::cout << "HP: " << test.getHitPoints() << std::endl;
	std::cout << "Energy: " << test.getEnergyPoints() << std::endl;
	std::cout << "Attack: " << test.getAttackDamage() << std::endl;
	
	std::cout << "\nUsing stream operator:" << std::endl;
	std::cout << test << std::endl;
}

void testMultipleClapTraps()
{
	printSeparator("MULTIPLE CLAPTRAPS BATTLE");
	
	ClapTrap team1[3] = {ClapTrap("Alpha"), ClapTrap("Beta"), ClapTrap("Gamma")};
	ClapTrap team2[3] = {ClapTrap("Delta"), ClapTrap("Echo"), ClapTrap("Foxtrot")};
	
	// Set different attack damages
	for (int i = 0; i < 3; i++)
	{
		team1[i].setAttackDamage(i + 1);
		team2[i].setAttackDamage(i + 2);
	}
	
	std::cout << "Team 1:" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << team1[i] << std::endl;
	
	std::cout << "\nTeam 2:" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << team2[i] << std::endl;
	
	std::cout << "\nBattle simulation:" << std::endl;
	for (int round = 1; round <= 3; round++)
	{
		std::cout << "\n--- Round " << round << " ---" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			if (team1[i].getHitPoints() > 0 && team2[i].getHitPoints() > 0)
			{
				team1[i].attack(team2[i].getName());
				team2[i].takeDamage(team1[i].getAttackDamage());
				
				if (team2[i].getHitPoints() > 0)
				{
					team2[i].attack(team1[i].getName());
					team1[i].takeDamage(team2[i].getAttackDamage());
				}
			}
		}
	}
	
	std::cout << "\nFinal status:" << std::endl;
	std::cout << "Team 1:" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << team1[i] << std::endl;
	
	std::cout << "\nTeam 2:" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << team2[i] << std::endl;
}

int main()
{
	try
	{
		testConstructorsAndDestructors();
		testBasicFunctionality();
		testEnergyDepletion();
		testDeathScenarios();
		testEdgeCases();
		testGettersAndSetters();
		testMultipleClapTraps();
		
		printSeparator("ALL TESTS COMPLETED");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}

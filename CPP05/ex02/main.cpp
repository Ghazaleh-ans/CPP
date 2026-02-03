/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:00:00 by gansari           #+#    #+#             */
/*   Updated: 2026/01/27 20:01:09 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << "========================================" << std::endl;
	std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat bob("Bob", 137);  // Grade 137 - can execute (137)
		ShrubberyCreationForm shrub("home");
		
		std::cout << bob << std::endl;
		std::cout << shrub << std::endl;
		
		bob.signForm(shrub);
		bob.executeForm(shrub);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "=== Test 2: RobotomyRequestForm ===" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat alice("Alice", 45);  // Grade 45 - can execute (45)
		RobotomyRequestForm robotomy("Bender");
		
		std::cout << alice << std::endl;
		std::cout << robotomy << std::endl;
		
		alice.signForm(robotomy);
		alice.executeForm(robotomy);
		
		// Try again to see the 50% success rate
		std::cout << "\n--- Trying again ---" << std::endl;
		alice.executeForm(robotomy);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "=== Test 3: PresidentialPardonForm ===" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat president("President", 1);  // Grade 1 - highest
		PresidentialPardonForm pardon("Arthur Dent");
		
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		
		president.signForm(pardon);
		president.executeForm(pardon);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "=== Test 4: Execute without signing ===" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 1);
		ShrubberyCreationForm unsignedForm("garden");
		
		std::cout << unsignedForm << std::endl;
		charlie.executeForm(unsignedForm);  // Should fail - not signed
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "=== Test 5: Grade too low to execute ===" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat intern("Intern", 100);
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Criminal");
		
		std::cout << intern << std::endl;
		std::cout << pardon << std::endl;
		
		boss.signForm(pardon);  // Boss signs it
		intern.executeForm(pardon);  // Intern tries to execute (should fail)
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "=== Test 6: Polymorphism ===" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		Bureaucrat supreme("Supreme Leader", 1);
		
		// Array of pointers to abstract base class!
		AForm* forms[3];
		forms[0] = new ShrubberyCreationForm("office");
		forms[1] = new RobotomyRequestForm("Target");
		forms[2] = new PresidentialPardonForm("Prisoner");
		
		// Process all forms uniformly
		for (int i = 0; i < 3; i++) {
			std::cout << "\n--- Form " << i + 1 << " ---" << std::endl;
			std::cout << *forms[i] << std::endl;
			supreme.signForm(*forms[i]);
			supreme.executeForm(*forms[i]);
		}
		
		// Cleanup
		for (int i = 0; i < 3; i++) {
			delete forms[i];
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "=== Test 7: Edge cases ===" << std::endl;
	std::cout << "========================================" << std::endl;
	try {
		// Exactly at the boundary
		Bureaucrat exactGrade("Exact", 145);
		ShrubberyCreationForm shrub("boundary");
		
		std::cout << exactGrade << std::endl;
		exactGrade.signForm(shrub);  // Should succeed (145 == 145)
		
		exactGrade.decrementGrade();  // Now grade 146
		std::cout << exactGrade << std::endl;
		
		ShrubberyCreationForm shrub2("boundary2");
		exactGrade.signForm(shrub2);  // Should fail (146 > 145)
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "=== All tests completed! ===" << std::endl;
	std::cout << "========================================" << std::endl;

	return 0;
}
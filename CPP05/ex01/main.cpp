/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:35:00 by gansari           #+#    #+#             */
/*   Updated: 2026/01/09 16:58:12 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	std::cout << "=== Test 1: Create valid forms ===" << std::endl;
	try {
		Form formA("Tax Form", 50, 25);
		std::cout << formA << std::endl;
		
		Form formB("Presidential Pardon", 5, 5);
		std::cout << formB << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Invalid form creation ===" << std::endl;
	try {
		Form invalidForm("Invalid", 0, 50);  // Grade too high
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Form invalidForm("Invalid", 50, 200);  // Grade too low
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Successful signing ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 40);
		Form taxForm("Tax Form", 50, 25);
		
		std::cout << "Before signing: " << taxForm << std::endl;
		bob.signForm(taxForm);  // Bob's grade 40 < 50 required → Success!
		std::cout << "After signing: " << taxForm << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Failed signing (grade too low) ===" << std::endl;
	try {
		Bureaucrat intern("Intern", 100);
		Form importantForm("Important Contract", 50, 25);
		
		std::cout << intern << std::endl;
		std::cout << importantForm << std::endl;
		
		intern.signForm(importantForm);  // Grade 100 > 50 required → Fail!
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Multiple bureaucrats, same form ===" << std::endl;
	try {
		Form contract("Contract", 75, 50);
		Bureaucrat alice("Alice", 50);
		Bureaucrat charlie("Charlie", 100);
		
		alice.signForm(contract);    // Should succeed (50 < 75)
		charlie.signForm(contract);  // Already signed, but let's try
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Edge cases ===" << std::endl;
	try {
		Form easyForm("Easy Form", 150, 150);
		Bureaucrat lowLevel("Low Level", 150);
		
		std::cout << lowLevel << std::endl;
		std::cout << easyForm << std::endl;
		lowLevel.signForm(easyForm);  // Exactly at limit
		std::cout << easyForm << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

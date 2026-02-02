/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:00:00 by gansari           #+#    #+#             */
/*   Updated: 2026/02/02 17:00:00 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	std::cout << "========================================" << std::endl;
	std::cout << "=== Test 1: Intern creates valid forms ===" << std::endl;
	std::cout << "========================================" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form1;
		AForm* form2;
		AForm* form3;

		std::cout << "\n--- Creating shrubbery creation form ---" << std::endl;
		form1 = someRandomIntern.makeForm("shrubbery creation", "home");
		if (form1) {
			std::cout << *form1 << std::endl;
			delete form1;
		}

		std::cout << "\n--- Creating robotomy request form ---" << std::endl;
		form2 = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form2) {
			std::cout << *form2 << std::endl;
			delete form2;
		}

		std::cout << "\n--- Creating presidential pardon form ---" << std::endl;
		form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		if (form3) {
			std::cout << *form3 << std::endl;
			delete form3;
		}
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "=== Test 2: Intern with invalid form name ===" << std::endl;
	std::cout << "========================================" << std::endl;
	{
		Intern someRandomIntern;
		AForm* invalidForm;

		std::cout << "\n--- Trying to create non-existent form ---" << std::endl;
		invalidForm = someRandomIntern.makeForm("invalid form name", "target");
		if (invalidForm == NULL) {
			std::cout << "Form creation failed as expected (returned NULL)" << std::endl;
		}

		std::cout << "\n--- Another invalid form ---" << std::endl;
		invalidForm = someRandomIntern.makeForm("coffee making", "office");
		if (invalidForm == NULL) {
			std::cout << "Form creation failed as expected (returned NULL)" << std::endl;
		}
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "=== Test 3: Complete workflow with Intern ===" << std::endl;
	std::cout << "========================================" << std::endl;
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		AForm* rrf;

		std::cout << "\n--- Intern creates robotomy request ---" << std::endl;
		rrf = intern.makeForm("robotomy request", "Bender");

		if (rrf) {
			std::cout << "\n" << boss << std::endl;
			std::cout << *rrf << std::endl;

			std::cout << "\n--- Boss signs the form ---" << std::endl;
			boss.signForm(*rrf);

			std::cout << "\n--- Boss executes the form ---" << std::endl;
			boss.executeForm(*rrf);

			delete rrf;
		}
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "=== Test 4: Multiple forms from same intern ===" << std::endl;
	std::cout << "========================================" << std::endl;
	{
		Intern intern;
		Bureaucrat highLevel("High Level Bureaucrat", 1);

		AForm* forms[3];
		forms[0] = intern.makeForm("shrubbery creation", "garden");
		forms[1] = intern.makeForm("robotomy request", "criminal");
		forms[2] = intern.makeForm("presidential pardon", "Ford Prefect");

		std::cout << "\n--- Processing all forms ---" << std::endl;
		for (int i = 0; i < 3; i++) {
			if (forms[i]) {
				std::cout << "\n" << *forms[i] << std::endl;
				highLevel.signForm(*forms[i]);
				highLevel.executeForm(*forms[i]);
			}
		}

		// Cleanup
		std::cout << "\n--- Cleaning up ---" << std::endl;
		for (int i = 0; i < 3; i++) {
			if (forms[i]) {
				delete forms[i];
			}
		}
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "=== Test 5: Intern with insufficient grades ===" << std::endl;
	std::cout << "========================================" << std::endl;
	{
		Intern intern;
		Bureaucrat lowLevel("Low Level Employee", 146);
		AForm* form;

		std::cout << "\n--- Creating presidential pardon ---" << std::endl;
		form = intern.makeForm("presidential pardon", "prisoner");

		if (form) {
			std::cout << "\n" << lowLevel << std::endl;
			std::cout << *form << std::endl;

			std::cout << "\n--- Trying to sign with insufficient grade ---" << std::endl;
			lowLevel.signForm(*form);

			delete form;
		}
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "=== Test 6: Copy and assignment test ===" << std::endl;
	std::cout << "========================================" << std::endl;
	{
		std::cout << "\n--- Testing intern copy and assignment ---" << std::endl;
		Intern intern1;
		Intern intern2(intern1);  // Copy constructor
		Intern intern3;
		intern3 = intern1;  // Assignment operator

		// All interns should work the same
		AForm* form1 = intern1.makeForm("shrubbery creation", "place1");
		AForm* form2 = intern2.makeForm("shrubbery creation", "place2");
		AForm* form3 = intern3.makeForm("shrubbery creation", "place3");

		if (form1) delete form1;
		if (form2) delete form2;
		if (form3) delete form3;
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "=== All tests completed! ===" << std::endl;
	std::cout << "========================================" << std::endl;

	return 0;
}

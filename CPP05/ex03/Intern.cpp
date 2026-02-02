/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:00:00 by gansari           #+#    #+#             */
/*   Updated: 2026/02/02 17:00:00 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {
}

static AForm* createShrubberyForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	struct FormType {
		std::string name;
		AForm* (*creator)(const std::string&);
	};

	FormType forms[] = {
		{"shrubbery creation", &createShrubberyForm},
		{"robotomy request", &createRobotomyForm},
		{"presidential pardon", &createPresidentialForm}
	};

	for (int i = 0; i < 3; i++) {
		if (forms[i].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].creator(target);
		}
	}

	std::cerr << "Error: Form name \"" << formName << "\" does not exist" << std::endl;
	return NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:00:00 by gansari           #+#    #+#             */
/*   Updated: 2026/01/27 19:58:34 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("Robotomy Request", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	// Check if form is signed
	if (!isSigned())
		throw FormNotSignedException();
	
	// Check if executor has high enough grade
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	
	// Execute the form's action: robotomize target (50% success rate)
	std::cout << "🔊 * DRILLING NOISES * BZZZZZZ BZZZZZZ *" << std::endl;
	
	// Seed random number generator (in real code, do this once at program start)
	static bool seeded = false;
	if (!seeded) {
		std::srand(std::time(NULL));
		seeded = true;
	}
	
	if (std::rand() % 2) {
		std::cout << "🤖 " << _target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "❌ Robotomy failed for " << _target << "!" << std::endl;
	}
}
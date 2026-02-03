/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:00:00 by gansari           #+#    #+#             */
/*   Updated: 2026/02/03 20:30:40 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("Presidential Pardon", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::cout << "🎖️  " << _target 
			<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
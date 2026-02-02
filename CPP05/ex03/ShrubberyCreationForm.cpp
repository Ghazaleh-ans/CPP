/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:00:00 by gansari           #+#    #+#             */
/*   Updated: 2026/01/27 19:57:24 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Shrubbery Creation", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	// Check if form is signed
	if (!isSigned())
		throw FormNotSignedException();
	
	// Check if executor has high enough grade
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	
	// Execute the form's action: create file with ASCII trees
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	
	if (!file.is_open()) {
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return;
	}
	
	file << "       ###" << std::endl;
	file << "      #o###" << std::endl;
	file << "    #####o###" << std::endl;
	file << "   #o#\\#|#/###" << std::endl;
	file << "    ###\\|/#o#" << std::endl;
	file << "     # }|{  #" << std::endl;
	file << "       }|{" << std::endl;
	file << std::endl;
	file << "      /\\~~/\\" << std::endl;
	file << "     /\\  ~  \\" << std::endl;
	file << "    /  \\~ ~ ~\\" << std::endl;
	file << "   /~~  \\~  ~ \\" << std::endl;
	file << "  /   ~  \\  ~  \\" << std::endl;
	file << " /~ ~ ~   \\~ ~  \\" << std::endl;
	file << "/___________\\____\\" << std::endl;
	file << "      |   |" << std::endl;
	file << "      |___|" << std::endl;
	
	file.close();
	std::cout << "🌲 Shrubbery created at " << filename << std::endl;
}
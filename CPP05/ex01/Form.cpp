/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:07:40 by gansari           #+#    #+#             */
/*   Updated: 2026/01/09 16:54:47 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() 
	: _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), 
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _isSigned;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

// beSigned function - THIS IS KEY!
void Form::beSigned(const Bureaucrat& bureaucrat) {
	// Check if bureaucrat's grade is good enough
	// Remember: LOWER number = BETTER grade
	// So if bureaucrat has grade 40 and form needs grade 50:
	// 40 < 50 means bureaucrat is BETTER than required → OK!
	
	if (bureaucrat.getGrade() > _gradeToSign) {
		// Bureaucrat's grade is worse than required
		throw GradeTooLowException();
	}
	
	// Grade is good enough, sign the form
	_isSigned = true;
}

// Exception implementations
const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

// Insertion operator overload
std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << "Form: " << form.getName() 
		<< ", signed: " << (form.isSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute();
	return out;
}
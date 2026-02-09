/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:15:10 by gansari           #+#    #+#             */
/*   Updated: 2026/02/09 17:57:39 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Non-instantiable -> private
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isCharLiteral(const std::string& str) {
	return str.length() == 3 && str[0] == '\'' && str[2] == '\'';
}

bool ScalarConverter::isPseudoLiteral(const std::string& str) {
	return str == "nan" || str == "nanf" ||
		str == "+inf" || str == "+inff" ||
		str == "-inf" || str == "-inff" ||
		str == "inf" || str == "inff";
}

bool ScalarConverter::isIntLiteral(const std::string& str) {
	if (str.empty())
		return false;
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i >= str.length())
		return false;
	for (; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloatLiteral(const std::string& str) {
	if (str.empty())
		return false;
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
		return true;
	if (str[str.length() - 1] != 'f')
		return false;
	std::string numPart = str.substr(0, str.length() - 1);
	if (numPart.empty())
		return false;
	size_t i = 0;
	if (numPart[i] == '+' || numPart[i] == '-')
		i++;
	bool hasDot = false;
	bool hasDigit = false;
	for (; i < numPart.length(); i++) {
		if (numPart[i] == '.') {
			if (hasDot)  // Second dot
				return false;
			hasDot = true;
		} else if (std::isdigit(numPart[i])) {
			hasDigit = true;
		} else {
			return false;
		}
	}
	return hasDigit;
}

bool ScalarConverter::isDoubleLiteral(const std::string& str) {
	if (str.empty())
		return false;
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return true;
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	bool hasDot = false;
	bool hasDigit = false;
	for (; i < str.length(); i++) {
		if (str[i] == '.') {
			if (hasDot) //second dot
				return false;
			hasDot = true;
		} else if (std::isdigit(str[i])) {
			hasDigit = true;
		} else {
			return false;
		}
	}
	return hasDigit && hasDot;
}

void ScalarConverter::displayChar(double value) {
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value)) {
		std::cout << "impossible" << std::endl; //inf or nan
		return;
	}
	if (value < std::numeric_limits<char>::min() || 
		value > std::numeric_limits<char>::max()) {
		std::cout << "impossible" << std::endl; //more than 8 bits
		return;
	}
	char c = static_cast<char>(value);
	if (c < 32 || c > 126) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "'" << c << "'" << std::endl;
	}
}

void ScalarConverter::displayInt(double value) {
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value)) {
		std::cout << "impossible" << std::endl; //inf or nan
		return;
	}
	if (value < std::numeric_limits<int>::min() || 
		value > std::numeric_limits<int>::max()) { //more than 32 bits
		std::cout << "impossible" << std::endl;
		return;
	}
	std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::displayFloat(double value) {
	std::cout << "float: ";
	float f = static_cast<float>(value);
	if (std::isnan(f)) {
		std::cout << "nanf" << std::endl;
	} else if (std::isinf(f)) {
		if (f > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
}

void ScalarConverter::displayDouble(double value) {
	std::cout << "double: ";
	if (std::isnan(value)) {
		std::cout << "nan" << std::endl;
	} else if (std::isinf(value)) {
		if (value > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	}
}

void ScalarConverter::convertFromChar(char c) {
	double value = static_cast<double>(c);

	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

void ScalarConverter::convertFromInt(int num) {
	double value = static_cast<double>(num);

	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

void ScalarConverter::convertFromFloat(float f) {
	double value = static_cast<double>(f);

	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

void ScalarConverter::convertFromDouble(double d) {
	displayChar(d);
	displayInt(d);
	displayFloat(d);
	displayDouble(d);
}

void ScalarConverter::convert(const std::string& literal) {
	// Handle char literal: 'c'
	if (isCharLiteral(literal)) {
		char c = literal[1];
		convertFromChar(c);
		return;
	}
	// Handle pseudo-literals
	if (isPseudoLiteral(literal)) {
		double value;
		if (literal == "nan" || literal == "nanf") {
			value = std::numeric_limits<double>::quiet_NaN();
		} else if (literal == "+inf" || literal == "+inff" || 
				literal == "inf" || literal == "inff") {
			value = std::numeric_limits<double>::infinity();
		} else {  // -inf or -inff
			value = -std::numeric_limits<double>::infinity();
		}
		convertFromDouble(value);
		return;
	}
	// Handle int literal
	if (isIntLiteral(literal)) {
		errno = 0;
		char* end;
		long value = std::strtol(literal.c_str(), &end, 10);
		if (errno == ERANGE || value < std::numeric_limits<int>::min() || 
			value > std::numeric_limits<int>::max()) {
			std::cout << "Error: Integer overflow" << std::endl;
			return;
		}
		convertFromInt(static_cast<int>(value));
		return;
	}
	// Handle float literal
	if (isFloatLiteral(literal)) {
		std::string numStr = literal.substr(0, literal.length() - 1);
		errno = 0;
		char* end;
		float value = std::strtof(numStr.c_str(), &end);
		if (errno == ERANGE) {
			std::cout << "Error: Float overflow" << std::endl;
			return;
		}
		convertFromFloat(value);
		return;
	}
	// Handle double literal
	if (isDoubleLiteral(literal)) {
		errno = 0;
		char* end;
		double value = std::strtod(literal.c_str(), &end);
		if (errno == ERANGE) {
			std::cout << "Error: Double overflow" << std::endl;
			return;
		}
		convertFromDouble(value);
		return;
	}
	// Invalid input
	std::cout << "Error: Invalid literal format" << std::endl;
}
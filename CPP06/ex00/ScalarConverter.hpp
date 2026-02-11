/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:00:20 by gansari           #+#    #+#             */
/*   Updated: 2026/02/09 14:10:35 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cerrno>
#include <sstream>
#include <iomanip>

class ScalarConverter {
private:
	// Private -> prevents instantiation
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static bool isCharLiteral(const std::string& str);
	static bool isIntLiteral(const std::string& str);
	static bool isFloatLiteral(const std::string& str);
	static bool isDoubleLiteral(const std::string& str);
	static bool isPseudoLiteral(const std::string& str);

	static void convertFromChar(char c);
	static void convertFromInt(int value);
	static void convertFromFloat(float value);
	static void convertFromDouble(double value);
	
	static void displayChar(double value);
	static void displayInt(double value);
	static void displayFloat(double value);
	static void displayDouble(double value);

public:
	static void convert(const std::string& literal);
};

#endif
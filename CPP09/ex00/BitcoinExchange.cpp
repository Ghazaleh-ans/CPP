/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:25:03 by gansari           #+#    #+#             */
/*   Updated: 2026/04/29 14:13:10 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib> // std::atof
#include <cerrno>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _db(other._db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static bool isLeapYear(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	// Must be exactly 10 characters: YYYY-MM-DD
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7) continue;
		if (!std::isdigit(date[i]))
			return false;
	}

	int year  = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear(year))
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		return false;

	return true;
}

bool BitcoinExchange::isValidValue(const std::string& token, double& out)
{
	if (token.empty())
		return false;
	bool hasDot = false;
	for (size_t i = 0; i < token.size(); ++i)
	{
		char c = token[i];
		if (i == 0 && c == '+')
			continue;
		if (c == '.')
		{
			if (hasDot) return false;
			hasDot = true;
			continue;
		}
		if (!std::isdigit(c))
			return false;
	}
	char* endptr;
	errno = 0;
	double val = std::strtod(token.c_str(), &endptr);
	if (errno != 0 || endptr == token.c_str() || *endptr != '\0')
		return false;

	out = val;
	return true;
}

void BitcoinExchange::parseCsvLine(const std::string& line,
								std::string& date, double& rate)
{
	std::stringstream ss(line);
	std::string rateStr;

	if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
		throw std::runtime_error("Malformed CSV line: " + line);

	while (!rateStr.empty() && std::isspace((unsigned char)rateStr[rateStr.size()-1]))
		rateStr.erase(rateStr.size()-1);
	while (!date.empty() && std::isspace((unsigned char)date[date.size()-1]))
		date.erase(date.size()-1);

	char* endptr;
	errno = 0;
	rate = std::strtod(rateStr.c_str(), &endptr);
	if (errno != 0 || endptr == rateStr.c_str() || *endptr != '\0')
		throw std::runtime_error("Bad rate in CSV: " + line);
}

void BitcoinExchange::parseInputLine(const std::string& line,
									std::string& date, std::string& valueStr)
{
	size_t sep = line.find(" | ");
	if (sep == std::string::npos)
		throw std::runtime_error("bad input => " + line);

	date = line.substr(0, sep);
	valueStr = line.substr(sep + 3);

	while (!date.empty() && std::isspace((unsigned char)date[date.size()-1]))
		date.erase(date.size()-1);
	while (!valueStr.empty() && std::isspace((unsigned char)valueStr[valueStr.size()-1]))
		valueStr.erase(valueStr.size()-1);
}

double BitcoinExchange::getRate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _db.find(date);
	if (it != _db.end())
		return it->second;

	it = _db.lower_bound(date);
	if (it == _db.begin())
		throw std::runtime_error("no exchange rate found for date: " + date);

	--it;
	return it->second;
}

void BitcoinExchange::loadDatabase(const std::string& dbPath)
{
	std::ifstream file(dbPath.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		if (!line.empty() && std::isspace((unsigned char)line[line.size()-1]))
			line.erase(line.size()-1);
		if (line.empty())
			continue;
		if (firstLine)
		{
			firstLine = false;
			if (line.find("date") != std::string::npos)
				continue;
		}
		std::string date;
		double rate = 0.0;
		try
		{
			parseCsvLine(line, date, rate);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Warning: skipping malformed DB line: "
					<< e.what() << std::endl;
			continue;
		}
		_db[date] = rate;
	}
	if (_db.empty())
		throw std::runtime_error("Error: database is empty.");
}

void BitcoinExchange::processInput(const std::string& inputPath) const
{
	std::ifstream file(inputPath.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		if (!line.empty() && std::isspace((unsigned char)line[line.size()-1]))
			line.erase(line.size()-1);
		if (line.empty())
			continue;
		if (firstLine)
		{
			firstLine = false;
			if (line.find("date") != std::string::npos &&
				line.find("value") != std::string::npos)
				continue;
		}

		std::string date;
		std::string valueStr;

		try
		{
			parseInputLine(line, date, valueStr);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			continue;
		}

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		double value = 0.0;
		if (!valueStr.empty() && valueStr[0] == '-')
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (!isValidValue(valueStr, value))
		{
			std::cerr << "Error: bad input => " << valueStr << std::endl;
			continue;
		}
		if (value > 1000.0)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		try
		{
			double rate = getRate(date);
			double result = value * rate;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:27:03 by gansari           #+#    #+#             */
/*   Updated: 2026/02/24 15:21:32 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <stdexcept>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void loadDatabase(const std::string& dbPath);
	void processInput(const std::string& inputPath) const;

private:
	// key = "YYYY-MM-DD", value = exchange rate
	std::map<std::string, double> _db;

	static bool isValidDate(const std::string& date);
	static bool isValidValue(const std::string& token, double& out);
	static void parseCsvLine(const std::string& line,
								std::string& date, double& rate);
	static void parseInputLine(const std::string& line,
								std::string& date, std::string& valueStr);

	double getRate(const std::string& date) const;
};

#endif
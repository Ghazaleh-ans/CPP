/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:28:22 by gansari           #+#    #+#             */
/*   Updated: 2025/08/20 15:44:56 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string &filename, const std::string &s1, const std::string &s2)
	: _filename(filename), _s1(s1), _s2(s2)
	{
		if (filename.empty())
		{
			std::cerr <<"Filename cannot be empty!" << std::endl;
		}
		if (s1.empty())
		{
			std::cerr << "Search string cannot be empty!" << std::endl;
		}
	}

FileReplacer::~FileReplacer()
{
}

bool FileReplacer::process() const {
	std::ifstream infile(_filename.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: could not open input file: " << _filename << std::endl;
		return false;
	}

	std::ofstream outfile((_filename + ".replace").c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: could not create output file: " << _filename << ".replace" << std::endl;
		return false;
	}

	std::string line;
	while (std::getline(infile, line)) {
		outfile << replaceAll(line);
		if (!infile.eof())
			outfile << "\n";
	}

	infile.close();
	outfile.close();
	return true;
}

std::string FileReplacer::replaceAll(const std::string &line) const {
	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = line.find(_s1, pos)) != std::string::npos) {
		result.append(line.substr(pos, found - pos));
		result.append(_s2);
		pos = found + _s1.length();
	}
	result.append(line.substr(pos));
	return result;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:54:11 by gansari           #+#    #+#             */
/*   Updated: 2025/08/20 15:46:03 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be empty." << std::endl;
		return 1;
	}

	FileReplacer replacer(filename, s1, s2);
	if (!replacer.process()) {
		std::cerr << "Error: failed to process file." << std::endl;
		return 1;
	}
	std::cout << "File processed successfully. Replacements made from '" << s1 << "' to '" << s2 << "'." << std::endl;
	std::cout << "Successfully created " << filename << ".replace" << std::endl;
	return 0;
}

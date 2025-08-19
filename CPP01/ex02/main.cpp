/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:52:41 by gansari           #+#    #+#             */
/*   Updated: 2025/08/19 20:07:55 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

int main() {
	std::string	str;
	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "=== MEMORY ADDRESSES ===" << std::endl;
	std::cout << "Address of str: " << &str << std::endl;
	std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address held by stringREF: " << &stringREF << std::endl;

	std::cout << "\n=== VALUES ===" << std::endl;
	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
	
	std::cout << "\n=== DEMONSTRATION: All addresses should be the same ===" << std::endl;
	std::cout << "&str        = " << &str << std::endl;
	std::cout << "stringPTR   = " << stringPTR << std::endl;
	std::cout << "&stringREF  = " << &stringREF << std::endl;
	
	std::cout << "\n=== DEMONSTRATION: All values should be the same ===" << std::endl;
	std::cout << "str         = " << str << std::endl;
	std::cout << "*stringPTR  = " << *stringPTR << std::endl;
	std::cout << "stringREF   = " << stringREF << std::endl;
	
	std::cout << "\n=== KEY DIFFERENCES ===" << std::endl;
	std::cout << "Pointer stringPTR has its own address: " << &stringPTR << std::endl;
	std::cout << "Reference stringREF has NO separate address - it IS str" << std::endl;
	
	return 0;
}

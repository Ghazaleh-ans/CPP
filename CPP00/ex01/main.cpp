/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:14:43 by gansari           #+#    #+#             */
/*   Updated: 2025/08/18 15:47:32 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::cout << "\nEnter command: ";
		std::getline(std::cin, command);

		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContacts();
		else if (command == "EXIT")
		{
			std::cout << "Goodbye! All contacts will be lost." << std::endl;
			break;
		}
		else
			std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
	}
	return 0;
}

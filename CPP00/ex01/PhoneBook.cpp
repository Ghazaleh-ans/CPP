/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:52:07 by gansari           #+#    #+#             */
/*   Updated: 2025/08/18 15:39:47 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_currentIndex = 0;
	_contactCount = 0;
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::getInputFromUser(const std::string& prompt) const
{
	std::string input;

	std::cout << prompt;
	std::getline(std::cin, input);

	return input;
}

void PhoneBook::addContact()
{
	std::cout << "Adding new contact..." << std::endl;

	std::string firstName = getInputFromUser("Enter first name: ");
	std::string lastName = getInputFromUser("Enter last name: ");
	std::string nickname = getInputFromUser("Enter nickname: ");
	std::string phoneNumber = getInputFromUser("Enter phone number: ");
	std::string darkestSecret = getInputFromUser("Enter darkest secret: ");

	if (firstName.empty() || lastName.empty() || nickname.empty() ||
		phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "Error: All fields must be filled. Contact not saved." << std::endl;
		return;
	}
	_contacts[_currentIndex].setFirstName(firstName);
	_contacts[_currentIndex].setLastName(lastName);
	_contacts[_currentIndex].setNickname(nickname);
	_contacts[_currentIndex].setPhoneNumber(phoneNumber);
	_contacts[_currentIndex].setDarkestSecret(darkestSecret);

	std::cout << "Contact saved successfully!" << std::endl;

	_currentIndex = (_currentIndex + 1) % MAX_CONTACTS;
	if (_contactCount < MAX_CONTACTS)
		_contactCount++;
}

std::string PhoneBook::truncateString(const std::string& str, size_t width) const
{
	if (str.length() <= width)
		return str;
	else
		return str.substr(0, width - 1) + ".";
}

void PhoneBook::displayContactList() const
{
	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < _contactCount; i++)
	{
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << truncateString(_contacts[i].getFirstName(), 10) << "|"
				<< std::setw(10) << truncateString(_contacts[i].getLastName(), 10) << "|"
				<< std::setw(10) << truncateString(_contacts[i].getNickname(), 10) << std::endl;
	}
}

void PhoneBook::displayFullContact(int index)
{
	if (index < 0 || index >= _contactCount)
	{
		std::cout << "Error: Invalid contact index." << std::endl;
		return;
	}
	std::cout << "\n--- Contact Details ---" << std::endl;
	_contacts[index].displayContact();
}

void PhoneBook::searchContacts()
{
	if (_contactCount == 0)
	{
		std::cout << "No contacts stored." << std::endl;
		return;
	}
	std::cout << "\n--- Contact List ---" << std::endl;
	displayContactList();

	std::string input = getInputFromUser("\nEnter contact index to display: ");

	for (size_t i = 0; i < input.length(); ++i)
	{
		if (!std::isdigit(input[i]))
		{
			std::cout << "Error: Invalid index format." << std::endl;
			return;
		}
	}

	int index = std::atoi(input.c_str());
	displayFullContact(index);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:52:18 by gansari           #+#    #+#             */
/*   Updated: 2025/06/20 17:55:05 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>       // For formatting output (setw, etc.)

class PhoneBook
{
private:
	static const int MAX_CONTACTS = 8;
	Contact _contacts[MAX_CONTACTS];
	int _currentIndex;
	int _contactCount;
public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContacts();
	void displayContactList() const;
	void displayFullContact(int index);
	std::string truncateString(const std::string& str, size_t width) const;
	std::string getInputFromUser(const std::string& prompt) const;

	/*
	* HELPER METHODS EXPLANATION:
	* - displayContactList(): Shows contacts in table format
	* - displayFullContact(): Shows all details of one contact
	* - truncateString(): Cuts long strings and adds '.' if needed
	* - getInputFromUser(): Gets user input with prompt
	*/
};

#endif // PHONEBOOK_HPP

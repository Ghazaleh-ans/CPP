/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:21:15 by gansari           #+#    #+#             */
/*   Updated: 2025/08/18 15:01:41 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	_firstName = "";
	_lastName = "";
	_nickname = "";
	_phoneNumber = "";
	_darkestSecret = "";
}

Contact::~Contact()
{
}

void Contact::setFirstName(const std::string& firstName)
{
	_firstName = firstName;
}

void Contact::setLastName(const std::string& lastName)
{
	_lastName = lastName;
}

void Contact::setNickname(const std::string& nickname)
{
	_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
	_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
	return _firstName;
}

std::string Contact::getLastName() const
{
	return _lastName;
}

std::string Contact::getNickname() const
{
	return _nickname;
}

std::string Contact::getPhoneNumber() const
{
	return _phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return _darkestSecret;
}

void Contact::displayContact() const
{
	std::cout << "First Name: " << getFirstName() << std::endl;
	std::cout << "Last Name: " << getLastName() << std::endl;
	std::cout << "Nickname: " << getNickname() << std::endl;
	std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << getDarkestSecret() << std::endl;
}

bool Contact::isComplete() const
{
	return !_firstName.empty() &&
		!_lastName.empty() &&
		!_nickname.empty() &&
		!_phoneNumber.empty() &&
		!_darkestSecret.empty();
}

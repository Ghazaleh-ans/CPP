/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:08:36 by gansari           #+#    #+#             */
/*   Updated: 2025/09/09 12:22:57 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static const int MAX_INT_VALUE = INT_MAX >> 8; // 8,388,607
static const int MIN_INT_VALUE = INT_MIN >> 8; // -8,388,608
static const float MAX_FLOAT_VALUE = static_cast<float>(INT_MAX) / (1 << 8); //8388607.99609375f
static const float MIN_FLOAT_VALUE = static_cast<float>(INT_MIN) / (1 << 8); //-8388608.0f

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	if (intValue > MAX_INT_VALUE || intValue < MIN_INT_VALUE)
	{
		throw std::overflow_error("Integer value out of range for Fixed point representation");
	}
	this->value = intValue << bits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	if (floatValue > MAX_FLOAT_VALUE || floatValue < MIN_FLOAT_VALUE)
	{
		throw std::overflow_error("Float value out of range for Fixed point representation");
	}
	this->value = static_cast<int>(roundf(floatValue * (1 << bits)));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << bits));
}

int	Fixed::toInt(void) const
{
	return (this->value >> bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

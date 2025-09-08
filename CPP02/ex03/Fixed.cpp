/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:08:36 by gansari           #+#    #+#             */
/*   Updated: 2025/09/08 18:51:38 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <stdexcept>

static const int FIXED_INT32_MAX = 2147483647; // 2^31 - 1
static const int FIXED_INT32_MIN = -2147483647 - 1; // -2^31
static const int MAX_INT_VALUE = FIXED_INT32_MAX >> 8; // 8,388,607
static const int MIN_INT_VALUE = FIXED_INT32_MIN >> 8; // -8,388,608
static const float MAX_FLOAT_VALUE = static_cast<float>(FIXED_INT32_MAX) / (1 << 8); //8388607.99609375f
static const float MIN_FLOAT_VALUE = static_cast<float>(FIXED_INT32_MIN) / (1 << 8); //-8388608.0f

Fixed::Fixed() : value(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int intValue)
{
	if (intValue > MAX_INT_VALUE || intValue < MIN_INT_VALUE)
	{
		throw std::overflow_error("Integer value out of range for Fixed point representation");
	}
	this->value = intValue << bits;
}

Fixed::Fixed(const float floatValue)
{
	if (floatValue > MAX_FLOAT_VALUE || floatValue < MIN_FLOAT_VALUE)
	{
		throw std::overflow_error("Float value out of range for Fixed point representation");
	}
	this->value = static_cast<int>(roundf(floatValue * (1 << bits)));
}

Fixed::Fixed(const Fixed &other)
{
	this->value = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->value < other.value);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->value > other.value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->value <= other.value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->value >= other.value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->value != other.value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->value + other.value);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->value - other.value);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	// For multiplication, we need to divide by (1 << bits) to maintain scale
	result.setRawBits((static_cast<long long>(this->value) * other.value) >> bits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.value == 0)
	{
		throw std::runtime_error("Division by zero");
	}
	Fixed result;
	// For division, we need to multiply by (1 << bits) to maintain scale
	result.setRawBits((static_cast<long long>(this->value) << bits) / other.value);
	return result;
}

Fixed &Fixed::operator++() // Prefix increment
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator++(int) // Postfix increment
{
	Fixed temp = *this;
	this->value++;
	return (temp);
}

Fixed &Fixed::operator--() // Prefix decrement
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--(int) // Postfix decrement
{
	Fixed temp = *this;
	this->value--;
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	Fixed::getRawBits(void) const
{
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

Fixed Fixed::abs(void) const
{
	Fixed result;
	result.setRawBits(this->value < 0 ? -this->value : this->value);
	return result;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

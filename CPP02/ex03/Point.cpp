/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:22:33 by gansari           #+#    #+#             */
/*   Updated: 2025/09/08 22:44:08 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::~Point()
{
}

Point::Point(const float xValue, const float yValue) : x(xValue), y(yValue)
{
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
}

Point &Point::operator=(const Point &other)
{
	(void)other;
	std::cerr << "Assignment operator not allowed for Point class." << std::endl;
	return *this;
}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}

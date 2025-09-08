/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:16:44 by gansari           #+#    #+#             */
/*   Updated: 2025/09/08 22:44:00 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

class Point
{
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	~Point();
	Point(const float xValue, const float yValue);
	Point(const Point &other);
	Point &operator=(const Point &other);
	Fixed getX() const;
	Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream &operator<<(std::ostream &out, const Point &point);
#endif
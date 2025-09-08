/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:33:50 by gansari           #+#    #+#             */
/*   Updated: 2025/09/08 22:55:35 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c)
{
	Fixed area = ((a.getX() * (b.getY() - c.getY())) +
				(b.getX() * (c.getY() - a.getY())) +
				(c.getX() * (a.getY() - b.getY()))).abs();
	return area / Fixed(2);
}

bool isEqual(const Fixed& a, const Fixed& b, const Fixed& epsilon)
{
	Fixed diff = (a - b).abs();
	return diff <= epsilon;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed A = area(a, b, c);
	Fixed A1 = area(point, b, c);
	Fixed A2 = area(a, point, c);
	Fixed A3 = area(a, b, point);

	Fixed epsilon(0.001f);
	Fixed sum = A1 + A2 + A3;

	return (isEqual(A, sum, epsilon) && 
			A1 > epsilon && A2 > epsilon && A3 > epsilon);
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
	out << "(" << point.getX().toFloat() << ", " << point.getY().toFloat() << ")";
	return out;
}
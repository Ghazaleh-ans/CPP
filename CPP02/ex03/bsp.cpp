/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:33:50 by gansari           #+#    #+#             */
/*   Updated: 2025/09/08 22:43:48 by gansari          ###   ########.fr       */
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

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed A = area(a, b, c);
	Fixed A1 = area(point, b, c);
	Fixed A2 = area(a, point, c);
	Fixed A3 = area(a, b, point);

	return (A == A1 + A2 + A3 && A1 != Fixed(0) && A2 != Fixed(0) && A3 != Fixed(0));
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
	out << "(" << point.getX().toFloat() << ", " << point.getY().toFloat() << ")";
	return out;
}
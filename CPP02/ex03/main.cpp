/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:16:28 by gansari           #+#    #+#             */
/*   Updated: 2025/09/08 22:36:38 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main()
{
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);

	Point insidePoint(1, 1);
	Point outsidePoint(6, 6);
	Point edgePoint(0, 2);
	Point vertexPoint(0, 0);

	std::cout << "Triangle vertices: A" << a << ", B" << b << ", C" << c << std::endl;

	std::cout << "Testing point " << insidePoint << ": ";
	if (bsp(a, b, c, insidePoint))
		std::cout << "Inside the triangle." << std::endl;
	else
		std::cout << "Outside the triangle." << std::endl;

	std::cout << "Testing point " << outsidePoint << ": ";
	if (bsp(a, b, c, outsidePoint))
		std::cout << "Inside the triangle." << std::endl;
	else
		std::cout << "Outside the triangle." << std::endl;

	std::cout << "Testing point " << edgePoint << ": ";
	if (bsp(a, b, c, edgePoint))
		std::cout << "Inside the triangle." << std::endl;
	else
		std::cout << "Outside the triangle." << std::endl;

	std::cout << "Testing point " << vertexPoint << ": ";
	if (bsp(a, b, c, vertexPoint))
		std::cout << "Inside the triangle." << std::endl;
	else
		std::cout << "Outside the triangle." << std::endl;

	return 0;
}
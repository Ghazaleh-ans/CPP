/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:19:34 by gansari           #+#    #+#             */
/*   Updated: 2026/02/17 15:48:16 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

static void printSeparator(const std::string &title)
{
	std::cout << "\n--- " << title << " ---\n";
}

int main(void)
{
	std::cout << "\n--- Subject Required Test ---\n";
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	// Expected output:
	// a = 3, b = 2
	// min(a, b) = 2
	// max(a, b) = 3
	// c = chaine2, d = chaine1
	// min(c, d) = chaine1
	// max(c, d) = chaine2

	std::cout << "\n--- swap with doubles ---\n";
	double x = 3.14;
	double y = 2.71;
	std::cout << "Before: x = " << x << ", y = " << y << std::endl;
	::swap(x, y);
	std::cout << "After:  x = " << x << ", y = " << y << std::endl;

	std::cout << "\n--- Smin/max with chars ---\n";
	char ch1 = 'z';
	char ch2 = 'a';
	std::cout << "min('z', 'a') = " << ::min(ch1, ch2) << std::endl;
	std::cout << "max('z', 'a') = " << ::max(ch1, ch2) << std::endl;

	std::cout << "\n--- Equality case (should return second parameter) ---\n";
	int eq1 = 42;
	int eq2 = 42;
	const int &minResult = ::min(eq1, eq2);
	const int &maxResult = ::max(eq1, eq2);
	std::cout << "min(42, 42) returns value: " << minResult << std::endl;
	std::cout << "min returns address of eq2 (second param)? "
			<< (&minResult == &eq2 ? "YES" : "NO") << std::endl;
	std::cout << "max(42, 42) returns value: " << maxResult << std::endl;
	std::cout << "max returns address of eq2 (second param)? "
			<< (&maxResult == &eq2 ? "YES" : "NO") << std::endl;
	std::cout << "\n--- Negative integers ---\n";
	int neg1 = -10;
	int neg2 = -5;
	std::cout << "min(-10, -5) = " << ::min(neg1, neg2) << std::endl;  // -10
	std::cout << "max(-10, -5) = " << ::max(neg1, neg2) << std::endl;  // -5

	std::cout << "\n--- Explicit template instantiation ---\n";
	std::cout << "Implicit: min(3, 5) = " << ::min(3, 5) << std::endl;

	std::cout << "Explicit: min<int>(3, 5) = " << ::min<int>(3, 5) << std::endl;
	std::cout << "Explicit: min<double>(3.0, 5.0) = " << ::min<double>(3.0, 5.0) << std::endl;

	return 0;
}
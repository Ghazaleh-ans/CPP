/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:19:34 by gansari           #+#    #+#             */
/*   Updated: 2026/02/17 16:01:58 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

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
	std::cout << "eq1 value : " << eq1 <<std::endl;
	std::cout << "eq2 value : " << eq2 <<std::endl;
	std::cout << "eq1 address : " << &eq1 << std::endl;
	std::cout << "eq2 address : " << &eq2 << std::endl;
	const int &minResult = ::min(eq1, eq2);
	std::cout << "min(eq1, eq2) result address : " << &minResult << std::endl;
	std::cout << "min returns address of eq2 (second param)? "
			<< (&minResult == &eq2 ? "YES" : "NO") << std::endl;
	const int &maxResult = ::max(eq1, eq2);
	std::cout << "max(eq1, eq2) result address : " << &maxResult << std::endl;
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
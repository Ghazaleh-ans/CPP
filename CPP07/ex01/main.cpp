/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:45:15 by gansari           #+#    #+#             */
/*   Updated: 2026/04/21 16:22:57 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// print elements of any type
template <typename T>
void printElement(const T& x)
{
	std::cout << x << " ";
}

// doubles the value in place
template <typename T>
void doubleValue(T& x)
{
	x *= 2;
}

// prints an int
void printInt(const int& x)
{
	std::cout << x << " ";
}

// uppercases a char in place
void uppercaseChar(char& c)
{
	if (c >= 'a' && c <= 'z')
		c = static_cast<char>(c - 32);
}

int main(void)
{
	std::cout << "--- Test 1: int array with non-const function ---" << std::endl;
	{
		int arr[] = {1, 2, 3, 4, 5};
		std::size_t len = 5;

		std::cout << "Before: ";
		iter(arr, len, printElement<int>);
		std::cout << std::endl;

		iter(arr, len, doubleValue<int>);

		std::cout << "After doubleValue: ";
		iter(arr, len, printElement<int>);
		std::cout << std::endl;
	}

	std::cout << "\n--- Test 2: const int array (read-only) ---" << std::endl;
	{
		const int arr[] = {10, 20, 30, 40};
		std::size_t len = 4;

		std::cout << "Elements: ";
		iter(arr, len, printElement<int>);  // calls const overload
		std::cout << std::endl;
		// iter(arr, len, doubleValue<int>); // <-- would NOT compile: arr is const
	}

	std::cout << "\n--- Test 3: std::string array ---" << std::endl;
	{
		std::string words[] = {"hello", "world", "foo", "bar"};
		std::size_t len = 4;

		std::cout << "Words: ";
		iter(words, len, printElement<std::string>);
		std::cout << std::endl;
	}

	std::cout << "\n--- Test 4: char array with in-place modification ---" << std::endl;
	{
		char letters[] = {'a', 'b', 'c', 'd', 'e'};
		std::size_t len = 5;

		std::cout << "Before: ";
		iter(letters, len, printElement<char>);
		std::cout << std::endl;

		iter(letters, len, uppercaseChar);

		std::cout << "After uppercase: ";
		iter(letters, len, printElement<char>);
		std::cout << std::endl;
	}

	std::cout << "\n--- Test 5: double array ---" << std::endl;
	{
		double arr[] = {1.1, 2.2, 3.3};
		std::size_t len = 3;

		std::cout << "Doubles: ";
		iter(arr, len, printElement<double>);
		std::cout << std::endl;
	}

	std::cout << "\n--- Test 6: plain (non-template) function as 3rd arg ---" << std::endl;
	{
		int arr[] = {7, 14, 21};
		std::size_t len = 3;

		std::cout << "With printInt: ";
		iter(arr, len, printInt);
		std::cout << std::endl;
	}

	std::cout << "\n--- Test 7: zero-length array (edge case) ---" << std::endl;
	{
		int arr[] = {1, 2, 3};
		std::cout << "Zero-len call (no output expected): ";
		iter(arr, static_cast<std::size_t>(0), printElement<int>);
		std::cout << "(done)" << std::endl;
	}

	return 0;
}
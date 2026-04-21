/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:49:37 by gansari           #+#    #+#             */
/*   Updated: 2026/04/21 16:56:41 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

static void testDefaultConstructor()
{
	std::cout << "\n--- Test 1: Default Constructor ---" << std::endl;
	Array<int> arr;
	std::cout << "Empty array size: " << arr.size() << "\n";

	try {
		arr[0];
		std::cout << "ERROR: should have thrown!\n";
	} catch (const std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << "\n";
	}
}

static void testParamConstructor()
{
	std::cout << "\n--- Test 2: Parameterized Constructor (value initialization) ---" << std::endl;
	Array<int> intArr(5);
	std::cout << "int array[5] contents (should all be 0): ";
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";
	std::cout << "\n";

	Array<double> dblArr(3);
	std::cout << "double array[3] contents (should all be 0.0): ";
	for (unsigned int i = 0; i < dblArr.size(); i++)
		std::cout << dblArr[i] << " ";
	std::cout << "\n";

	// Assign values
	intArr[0] = 10;
	intArr[1] = 20;
	intArr[2] = 30;
	intArr[3] = 40;
	intArr[4] = 50;
	std::cout << "After assignment: ";
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";
	std::cout << "\n";
}

static void testCopyConstructor()
{
	std::cout << "\n--- Test 3: Copy Constructor (deep copy) ---" << std::endl;

	Array<int> original(3);
	original[0] = 1;
	original[1] = 2;
	original[2] = 3;

	// Copy construct
	Array<int> copy(original);

	std::cout << "Original: ";
	for (unsigned int i = 0; i < original.size(); i++)
		std::cout << original[i] << " ";
	std::cout << "\n";

	std::cout << "Copy:     ";
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << "\n";

	// Modify copy - original must NOT change
	copy[0] = 99;
	copy[1] = 99;

	std::cout << "After modifying copy[0] and copy[1] to 99:\n";
	std::cout << "Original: ";
	for (unsigned int i = 0; i < original.size(); i++)
		std::cout << original[i] << " ";
	std::cout << "\n";

	std::cout << "Copy:     ";
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << "\n";
}

static void testAssignmentOperator()
{
	std::cout << "\n--- Test 4: Assignment Operator (deep copy) ---" << std::endl;

	Array<int> a(3);
	a[0] = 10; a[1] = 20; a[2] = 30;

	Array<int> b(5);
	b[0] = 1; b[1] = 2; b[2] = 3; b[3] = 4; b[4] = 5;

	// Assign a to b (b's old memory freed, gets a's data)
	b = a;

	std::cout << "b after b = a (size should be 3): size=" << b.size() << "\n";
	std::cout << "b contents: ";
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << "\n";

	// Modifying a must not affect b
	a[0] = 999;
	std::cout << "After a[0]=999, b[0]=" << b[0] << " (should still be 10)\n";

	// Self-assignment (must not crash or corrupt)
	b = b;
	std::cout << "Self-assignment: b[0]=" << b[0] << " (should be 10)\n";
}

static void testBoundsChecking()
{
	std::cout << "\n--- Test 5: Bounds Checking ---" << std::endl;

	Array<int> arr(3);
	arr[0] = 42;

	// Valid access
	std::cout << "arr[0] = " << arr[0] << "\n";

	// Out of bounds: index == size (should throw)
	try {
		std::cout << arr[3];  // valid indices: 0, 1, 2
		std::cout << "ERROR: should have thrown!\n";
	} catch (const std::exception& e) {
		std::cout << "arr[3] threw: " << e.what() << "\n";
	}

	// Very large index
	try {
		arr[1000000];
		std::cout << "ERROR: should have thrown!\n";
	} catch (const std::exception& e) {
		std::cout << "arr[1000000] threw: " << e.what() << "\n";
	}
}

static void testConstArray()
{
	std::cout << "\n--- Test 6: Const Array ---" << std::endl;

	// Fill a regular array, then const-assign it
	Array<int> temp(3);
	temp[0] = 7; temp[1] = 8; temp[2] = 9;

	const Array<int> constArr(temp);

	// Read is allowed
	std::cout << "constArr[1] = " << constArr[1] << "\n";

	// Write is a COMPILE-TIME ERROR:
	// constArr[0] = 5;

	// Bounds check still works on const
	try {
		constArr[10];
		std::cout << "ERROR: should have thrown!\n";
	} catch (const std::exception& e) {
		std::cout << "constArr[10] threw: " << e.what() << "\n";
	}
}

static void testStringArray()
{
	std::cout << "\n--- Test 7: Array<std::string> ---" << std::endl;

	Array<std::string> strArr(3);

	// Default-initialized strings are empty
	std::cout << "Default string[0] = \"" << strArr[0] << "\"\n";

	strArr[0] = "hello";
	strArr[1] = "world";
	strArr[2] = "!";

	for (unsigned int i = 0; i < strArr.size(); i++)
		std::cout << "strArr[" << i << "] = " << strArr[i] << "\n";

	// Deep copy test with strings
	Array<std::string> copy = strArr;
	copy[0] = "MODIFIED";
	std::cout << "After copy[0]=\"MODIFIED\": original[0]=\"" << strArr[0] << "\"\n";
}

static void testZeroSize()
{
	std::cout << "\n--- Test 8: Zero-size array ---" << std::endl;

	Array<int> arr(0);
	std::cout << "Array(0) size: " << arr.size() << "\n";

	try {
		arr[0];
		std::cout << "ERROR: should have thrown!\n";
	} catch (const std::exception& e) {
		std::cout << "arr[0] on size-0 array threw: " << e.what() << "\n";
	}
}

int main()
{
	testDefaultConstructor();
	testParamConstructor();
	testCopyConstructor();
	testAssignmentOperator();
	testBoundsChecking();
	testConstArray();
	testStringArray();
	testZeroSize();

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:05:13 by gansari           #+#    #+#             */
/*   Updated: 2026/02/19 15:31:36 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void printResult(const std::string& label, bool passed)
{
	std::cout << (passed ? "[PASS] " : "[FAIL] ") << label << std::endl;
}

//  Test 1 – basic find in std::vector (success)

static void test_vector_found()
{
	std::cout << "\n=== Test 1: std::vector – value present ===" << std::endl;

	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(42);
	v.push_back(50);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 42);
		std::cout << "Found value: " << *it << std::endl;
		printResult("vector found 42", *it == 42);
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
		printResult("vector found 42", false);
	}
}

//  Test 2 – value NOT in vector → must throw

static void test_vector_not_found()
{
	std::cout << "\n=== Test 2: std::vector – value absent ===" << std::endl;

	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	try
	{
		easyfind(v, 99);
		printResult("vector throws for missing value", false); // should not reach here
	}
	catch (const std::exception& e)
	{
		std::cout << "Correctly threw: " << e.what() << std::endl;
		printResult("vector throws for missing value", true);
	}
}

//  Test 3 – std::list

static void test_list_found()
{
	std::cout << "\n=== Test 3: std::list – value present ===" << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);
	lst.push_back(35);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 25);
		std::cout << "Found value: " << *it << std::endl;
		printResult("list found 25", *it == 25);
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
		printResult("list found 25", false);
	}
}

//  Test 4 – std::deque

static void test_deque_found()
{
	std::cout << "\n=== Test 4: std::deque – value present ===" << std::endl;

	std::deque<int> dq;
	dq.push_back(100);
	dq.push_back(200);
	dq.push_back(300);

	try
	{
		std::deque<int>::iterator it = easyfind(dq, 200);
		std::cout << "Found value: " << *it << std::endl;
		printResult("deque found 200", *it == 200);
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
		printResult("deque found 200", false);
	}
}

//  Test 5 – first occurrence only (duplicates)

static void test_first_occurrence()
{
	std::cout << "\n=== Test 5: First occurrence with duplicates ===" << std::endl;

	std::vector<int> v;
	v.push_back(7);
	v.push_back(7);
	v.push_back(7);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 7);
		// it should point to the FIRST element (index 0)
		bool isFirst = (it == v.begin());
		std::cout << "Iterator points to first element: " << (isFirst ? "yes" : "no") << std::endl;
		printResult("first occurrence returned", isFirst);
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
		printResult("first occurrence returned", false);
	}
}

//  Test 6 – empty container must throw

static void test_empty_container()
{
	std::cout << "\n=== Test 6: Empty container ===" << std::endl;

	std::vector<int> v; // empty

	try
	{
		easyfind(v, 0);
		printResult("empty container throws", false);
	}
	catch (const std::exception& e)
	{
		std::cout << "Correctly threw: " << e.what() << std::endl;
		printResult("empty container throws", true);
	}
}

//  Test 7 – const container (const overload)

static void test_const_container()
{
	std::cout << "\n=== Test 7: const container ===" << std::endl;

	std::vector<int> tmp;
	tmp.push_back(11);
	tmp.push_back(22);
	tmp.push_back(33);

	const std::vector<int>& cv = tmp; // const reference

	try
	{
		std::vector<int>::const_iterator it = easyfind(cv, 22);
		std::cout << "Found value in const container: " << *it << std::endl;
		printResult("const container search", *it == 22);
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
		printResult("const container search", false);
	}
}

int main()
{
	test_vector_found();
	test_vector_not_found();
	test_list_found();
	test_deque_found();
	test_first_occurrence();
	test_empty_container();
	test_const_container();

	return 0;
}
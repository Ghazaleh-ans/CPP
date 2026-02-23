/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:36:04 by gansari           #+#    #+#             */
/*   Updated: 2026/02/23 21:20:28 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>  // std::find
#include "MutantStack.hpp"

static void printResult(const std::string& label, bool passed)
{
	std::cout << (passed ? "[PASS] " : "[FAIL] ") << label << std::endl;
}

static void test_subject_example()
{
	std::cout << "\n=== Test 1: Subject example ===" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top: " << mstack.top() << std::endl;   // 17
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl; // 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Iterating with MutantStack:" << std::endl;

	MutantStack<int>::iterator it  = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	printResult("std::stack copy from MutantStack", s.size() == mstack.size());
}

static void test_same_output_as_list()
{
	std::cout << "\n=== Test 2: MutantStack vs std::list same output ===" << std::endl;

	std::cout << "MutantStack output:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.pop();
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::vector<int> mutantOutput;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << std::endl;
		mutantOutput.push_back(*it);
	}

	std::cout << "std::list output:" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::vector<int> listOutput;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << *it << std::endl;
		listOutput.push_back(*it);
	}

	printResult("MutantStack and std::list produce same output", mutantOutput == listOutput);
}

static void test_stack_operations()
{
	std::cout << "\n=== Test 3: Stack operations ===" << std::endl;

	MutantStack<int> ms;

	printResult("empty() on new stack", ms.empty());

	ms.push(10);
	ms.push(20);
	ms.push(30);

	printResult("size() == 3",        ms.size() == 3);
	printResult("top() == 30",        ms.top() == 30);

	ms.pop();
	printResult("after pop, top == 20", ms.top() == 20);
	printResult("after pop, size == 2", ms.size() == 2);
}

static void test_const_iterator()
{
	std::cout << "\n=== Test 4: const_iterator ===" << std::endl;

	MutantStack<int> ms;
	ms.push(1);
	ms.push(2);
	ms.push(3);

	const MutantStack<int>& cms = ms;

	int sum = 0;
	for (MutantStack<int>::const_iterator it = cms.begin(); it != cms.end(); ++it)
		sum += *it;

	std::cout << "sum via const_iterator: " << sum << " (expected 6)" << std::endl;
	printResult("const_iterator sum == 6", sum == 6);
}

static void test_reverse_iterator()
{
	std::cout << "\n=== Test 5: reverse_iterator ===" << std::endl;

	MutantStack<int> ms;
	ms.push(1);
	ms.push(2);
	ms.push(3);

	// Stack order (bottom to top): 1, 2, 3
	// Reverse iteration: 3, 2, 1

	std::vector<int> reversed;
	for (MutantStack<int>::reverse_iterator it = ms.rbegin(); it != ms.rend(); ++it)
		reversed.push_back(*it);

	std::cout << "Reverse order: ";
	for (size_t i = 0; i < reversed.size(); ++i)
		std::cout << reversed[i] << " ";
	std::cout << std::endl;

	printResult("rbegin gives top element (3)", reversed[0] == 3);
	printResult("rend gives bottom element (1)", reversed[2] == 1);
}

static void test_copy()
{
	std::cout << "\n=== Test 6: Copy constructor and assignment ===" << std::endl;

	MutantStack<int> original;
	original.push(10);
	original.push(20);
	original.push(30);

	MutantStack<int> copy(original);
	MutantStack<int> assigned;
	assigned = original;

	printResult("copy has same size",     copy.size()     == original.size());
	printResult("assigned has same size", assigned.size() == original.size());
	printResult("copy top == 30",         copy.top()     == 30);
	printResult("assigned top == 30",     assigned.top() == 30);

	// Modifying copy should not affect original
	copy.push(999);
	printResult("copy is independent from original", copy.size() != original.size());
}

static void test_stl_algorithm()
{
	std::cout << "\n=== Test 7: STL algorithm on MutantStack ===" << std::endl;

	MutantStack<int> ms;
	ms.push(4);
	ms.push(8);
	ms.push(15);
	ms.push(16);
	ms.push(23);
	ms.push(42);

	MutantStack<int>::iterator found = std::find(ms.begin(), ms.end(), 15);
	printResult("std::find found 15",       found != ms.end() && *found == 15);

	MutantStack<int>::iterator notFound = std::find(ms.begin(), ms.end(), 99);
	printResult("std::find returns end() for missing value", notFound == ms.end());
}

static void test_string_type()
{
	std::cout << "\n=== Test 8: MutantStack<std::string> ===" << std::endl;

	MutantStack<std::string> ms;
	ms.push("hello");
	ms.push("world");
	ms.push("42");

	std::cout << "top: " << ms.top() << std::endl;

	std::string joined;
	for (MutantStack<std::string>::iterator it = ms.begin(); it != ms.end(); ++it)
		joined += *it + " ";

	std::cout << "all elements: " << joined << std::endl;
	printResult("string stack top == '42'", ms.top() == "42");
	printResult("string stack size == 3",   ms.size() == 3);
}

int main()
{
	test_subject_example();
	test_same_output_as_list();
	test_stack_operations();
	test_const_iterator();
	test_reverse_iterator();
	test_copy();
	test_stl_algorithm();
	test_string_type();

	return 0;
}
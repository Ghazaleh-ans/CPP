/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:40:43 by gansari           #+#    #+#             */
/*   Updated: 2026/04/27 15:27:59 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()
#include "Span.hpp"

static void printResult(const std::string& label, bool passed)
{
	std::cout << (passed ? "[PASS] " : "[FAIL] ") << label << std::endl;
}

static void test_subject_example()
{
	std::cout << "\n--- Test 1: Subject example ---" << std::endl;

	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	int shortest = sp.shortestSpan();
	int longest  = sp.longestSpan();

	std::cout << "shortestSpan: " << shortest << " (expected 2)" << std::endl;
	std::cout << "longestSpan:  " << longest  << " (expected 14)" << std::endl;

	printResult("shortest == 2", shortest == 2);
	printResult("longest  == 14", longest == 14);
}

static void test_overflow()
{
	std::cout << "\n--- Test 2: Adding beyond capacity ---" << std::endl;

	Span sp(3);
	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);

	try
	{
		sp.addNumber(4);
		printResult("overflow throws", false);
	}
	catch (const std::exception& e)
	{
		std::cout << "Correctly threw: " << e.what() << std::endl;
		printResult("overflow throws", true);
	}
}

static void test_too_few_elements()
{
	std::cout << "\n--- Test 3: Span with fewer than 2 elements ---" << std::endl;

	{
		Span sp(5);
		try
		{
			sp.shortestSpan();
			printResult("empty span shortestSpan throws", false);
		}
		catch (const std::exception& e)
		{
			std::cout << "Empty – correctly threw: " << e.what() << std::endl;
			printResult("empty span shortestSpan throws", true);
		}
	}

	{
		Span sp(5);
		sp.addNumber(42);
		try
		{
			sp.longestSpan();
			printResult("one-element longestSpan throws", false);
		}
		catch (const std::exception& e)
		{
			std::cout << "One element – correctly threw: " << e.what() << std::endl;
			printResult("one-element longestSpan throws", true);
		}
	}
}

static void test_add_range_large()
{
	std::cout << "\n--- Test 4: addRange with 10 000 numbers ---" << std::endl;

	const unsigned int N = 10000;
	Span sp(N);

	std::vector<int> source;
	srand(static_cast<unsigned int>(time(0)));
	for (unsigned int i = 0; i < N; ++i)
		source.push_back(rand());

	sp.addRange(source.begin(), source.end());

	std::cout << "Size after addRange: " << sp.size() << std::endl;
	printResult("size == 10000", sp.size() == N);

	int shortest = sp.shortestSpan();
	int longest  = sp.longestSpan();
	std::cout << "shortestSpan: " << shortest << std::endl;
	std::cout << "longestSpan:  " << longest  << std::endl;
	printResult("shortest >= 0", shortest >= 0);
	printResult("longest > shortest", longest > shortest);
}

static void test_add_range_list()
{
	std::cout << "\n--- Test 5: addRange from std::list ---" << std::endl;

	std::list<int> lst;
	lst.push_back(100);
	lst.push_back(50);
	lst.push_back(200);
	lst.push_back(75);

	Span sp(4);
	sp.addRange(lst.begin(), lst.end());

	std::cout << "shortestSpan: " << sp.shortestSpan() << " (expected 25)"  << std::endl;
	std::cout << "longestSpan:  " << sp.longestSpan()  << " (expected 150)" << std::endl;
	printResult("list addRange shortest == 25", sp.shortestSpan() == 25);
	printResult("list addRange longest  == 150", sp.longestSpan()  == 150);
}

static void test_add_range_overflow()
{
	std::cout << "\n--- Test 6: addRange overflow ---" << std::endl;

	Span sp(3);
	sp.addNumber(1);

	std::vector<int> big;
	big.push_back(2);
	big.push_back(3);
	big.push_back(4);

	try
	{
		sp.addRange(big.begin(), big.end());
		printResult("addRange overflow throws", false);
	}
	catch (const std::exception& e)
	{
		std::cout << "Correctly threw: " << e.what() << std::endl;
		printResult("addRange overflow throws", true);
	}
}

static void test_copy()
{
	std::cout << "\n--- Test 7: Copy constructor and assignment ---" << std::endl;

	Span original(5);
	original.addNumber(10);
	original.addNumber(30);
	original.addNumber(20);

	Span copy(original);
	Span assigned(10);
	assigned = original;

	printResult("copy shortest == original", copy.shortestSpan() == original.shortestSpan());
	printResult("assigned longest == original", assigned.longestSpan() == original.longestSpan());

	copy.addNumber(100);
	printResult("copy is independent from original", copy.size() != original.size());
}

static void test_identical_values()
{
	std::cout << "\n--- Test 8: Identical values - shortest span == 0 ---" << std::endl;

	Span sp(4);
	sp.addNumber(5);
	sp.addNumber(5);
	sp.addNumber(5);
	sp.addNumber(5);

	std::cout << "shortestSpan: " << sp.shortestSpan() << " (expected 0)" << std::endl;
	std::cout << "longestSpan: " << sp.longestSpan()  << " (expected 0)" << std::endl;
	printResult("shortest == 0", sp.shortestSpan() == 0);
	printResult("longest == 0", sp.longestSpan()  == 0);
}

int main()
{
	test_subject_example();
	test_overflow();
	test_too_few_elements();
	test_add_range_large();
	test_add_range_list();
	test_add_range_overflow();
	test_copy();
	test_identical_values();

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:35:49 by gansari           #+#    #+#             */
/*   Updated: 2026/03/09 15:35:58 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>

// Print a container's contents to stdout
template <typename Container>
static void printSequence(const Container& c)
{
	typename Container::const_iterator it = c.begin();
	while (it != c.end())
	{
		if (it != c.begin()) std::cout << " ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pm;
		pm.parseInput(argc, argv);

		// Capture the "before" state (vector holds original order)
		std::vector<int> before = pm.getVec();

		// Sort both containers (timing happens inside)
		pm.sortVector();
		pm.sortDeque();

		// Display
		std::cout << "Before: ";
		printSequence(before);

		std::cout << "After:  ";
		printSequence(pm.getVec());

		size_t n = pm.getVec().size();
		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time to process a range of " << n
				<< " elements with std::vector : "
				<< pm.getVecTime() << " us" << std::endl;
		std::cout << "Time to process a range of " << n
				<< " elements with std::deque  : "
				<< pm.getDeqTime() << " us" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
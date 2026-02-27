/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:13:56 by gansari           #+#    #+#             */
/*   Updated: 2026/02/27 16:19:45 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void parseInput(int argc, char** argv);

	void sortVector();
	void sortDeque();

	const std::vector<int>& getVec() const;
	const std::deque<int>& getDeq() const;
	double getVecTime() const;
	double getDeqTime() const;

private:
	std::vector<int> _vec;
	std::deque<int> _deq;
	double _vecTime;  // microseconds
	double _deqTime;

	static void fjVector(std::vector<int>& v);
	static void fjDeque(std::deque<int>& d);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:33:56 by gansari           #+#    #+#             */
/*   Updated: 2026/05/04 15:21:35 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <algorithm> // std::find, std::lower_bound
#include <climits> // INT_MAX
#include <ctime> // std::clock
#include <utility> // std::pair, std::make_pair

PmergeMe::PmergeMe() : _vecTime(0.0), _deqTime(0.0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
	: _vec(other._vec), _deq(other._deq),
	_vecTime(other._vecTime), _deqTime(other._deqTime) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
		_vecTime = other._vecTime;
		_deqTime = other._deqTime;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

const std::vector<int>& PmergeMe::getVec() const { return _vec; }
const std::deque<int>&  PmergeMe::getDeq() const { return _deq; }
double PmergeMe::getVecTime() const { return _vecTime; }
double PmergeMe::getDeqTime() const { return _deqTime; }

void PmergeMe::parseInput(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string token(argv[i]);

		if (token.empty())
			throw std::runtime_error("Error");
		for (size_t c = 0; c < token.size(); ++c)
		{
			if (!std::isdigit(static_cast<unsigned char>(token[c])))
				throw std::runtime_error("Error");
		}
		long val = 0;
		for (size_t c = 0; c < token.size(); ++c)
		{
			val = val * 10 + (token[c] - '0');
			if (val > INT_MAX)
				throw std::runtime_error("Error");
		}
		if (val == 0)
			throw std::runtime_error("Error");
		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
	}
	// if (_vec.empty())
	// 	throw std::runtime_error("Error");
}

static std::vector<size_t> makeInsertOrder(size_t n)
{
	std::vector<size_t> order;
	if (n <= 1)
		return order;

	std::vector<size_t> jac;
	jac.push_back(1);
	jac.push_back(3);
	while (jac.back() < n)
	{
		size_t next = jac.back() + 2 * jac[jac.size() - 2];
		jac.push_back(next);
	}

	for (size_t g = 1; g < jac.size(); ++g)
	{
		size_t hi = std::min(jac[g], n);
		size_t lo = jac[g - 1] + 1;
		if (lo > n) break;
		for (size_t i = hi; i >= lo; --i)
			order.push_back(i);
	}
	return order;
}

void PmergeMe::fjVector(std::vector<int>& v)
{
	size_t n = v.size();
	if (n <= 1) return;

	bool odd = (n % 2 != 0);
	int  straggler = 0;
	if (odd)
	{
		straggler = v.back();
		v.pop_back();
		n--;
	}

	size_t pc = n / 2;

	std::vector<std::pair<int, int> > pairs(pc);
	for (size_t i = 0; i < pc; ++i)
	{
		int a = v[2 * i];
		int b = v[2 * i + 1];
		pairs[i] = (a >= b) ? std::make_pair(a, b) : std::make_pair(b, a);
	}

	std::vector<int> largers;
	largers.reserve(pc);
	for (size_t i = 0; i < pc; ++i)
		largers.push_back(pairs[i].first);

	fjVector(largers);

	std::vector<std::pair<int, int> > sortedPairs(pc);
	std::vector<bool> used(pc, false);
	for (size_t i = 0; i < pc; ++i)
	{
		for (size_t j = 0; j < pc; ++j)
		{
			if (!used[j] && pairs[j].first == largers[i])
			{
				sortedPairs[i] = pairs[j];
				used[j] = true;
				break;
			}
		}
	}
	pairs = sortedPairs;

	std::vector<int> chain;
	chain.reserve(n + 1); //to avoid reallocation with odd numbers
	chain.push_back(pairs[0].second);
	for (size_t i = 0; i < pc; ++i)
		chain.push_back(pairs[i].first);

	std::vector<size_t> aPos(pc);
	for (size_t i = 0; i < pc; ++i)
		aPos[i] = i + 1;

	std::vector<size_t> order = makeInsertOrder(pc);

	for (size_t k = 0; k < order.size(); ++k)
	{
		size_t idx = order[k] - 1;
		int val = pairs[idx].second;
		size_t ubPos = aPos[idx];

		std::vector<int>::iterator beg = chain.begin();
		std::vector<int>::iterator ub  = beg + static_cast<long>(ubPos + 1);
		std::vector<int>::iterator pos = std::lower_bound(beg, ub, val);

		size_t insertIdx = static_cast<size_t>(pos - chain.begin());
		chain.insert(pos, val);

		for (size_t j = 0; j < pc; ++j)
			if (aPos[j] >= insertIdx)
				aPos[j]++;
	}

	if (odd)
	{
		std::vector<int>::iterator pos =
			std::lower_bound(chain.begin(), chain.end(), straggler);
		chain.insert(pos, straggler);
	}

	v = chain;
}

void PmergeMe::fjDeque(std::deque<int>& d)
{
	size_t n = d.size();
	if (n <= 1) return;

	bool odd = (n % 2 != 0);
	int  straggler = 0;
	if (odd) {
		straggler = d.back();
		d.pop_back();
		n--;
	}

	size_t pc = n / 2;

	std::vector<std::pair<int, int> > pairs(pc);
	for (size_t i = 0; i < pc; ++i)
	{
		int a = d[2 * i];
		int b = d[2 * i + 1];
		pairs[i] = (a >= b) ? std::make_pair(a, b) : std::make_pair(b, a);
	}

	std::deque<int> largers;
	for (size_t i = 0; i < pc; ++i)
		largers.push_back(pairs[i].first);

	fjDeque(largers);

	std::vector<std::pair<int, int> > sortedPairs(pc);
	std::vector<bool> used(pc, false);
	for (size_t i = 0; i < pc; ++i)
	{
		for (size_t j = 0; j < pc; ++j)
		{
			if (!used[j] && pairs[j].first == largers[i])
			{
				sortedPairs[i] = pairs[j];
				used[j] = true;
				break;
			}
		}
	}
	pairs = sortedPairs;

	std::deque<int> chain;
	chain.push_back(pairs[0].second);
	for (size_t i = 0; i < pc; ++i)
		chain.push_back(pairs[i].first);

	std::vector<size_t> aPos(pc);
	for (size_t i = 0; i < pc; ++i)
		aPos[i] = i + 1;

	std::vector<size_t> order = makeInsertOrder(pc);

	for (size_t k = 0; k < order.size(); ++k)
	{
		size_t idx  = order[k] - 1;
		int    val  = pairs[idx].second;
		size_t ubPos = aPos[idx];

		std::deque<int>::iterator beg = chain.begin();
		std::deque<int>::iterator ub  = beg + static_cast<long>(ubPos + 1);
		std::deque<int>::iterator pos = std::lower_bound(beg, ub, val);

		size_t insertIdx = static_cast<size_t>(pos - chain.begin());
		chain.insert(pos, val);

		for (size_t j = 0; j < pc; ++j)
			if (aPos[j] >= insertIdx)
				aPos[j]++;
	}

	if (odd)
	{
		std::deque<int>::iterator pos =
			std::lower_bound(chain.begin(), chain.end(), straggler);
		chain.insert(pos, straggler);
	}

	d = chain;
}

void PmergeMe::sortVector()
{
	std::clock_t start = std::clock();
	fjVector(_vec);
	std::clock_t end = std::clock();
	_vecTime = static_cast<double>(end - start)
			/ static_cast<double>(CLOCKS_PER_SEC) * 1e6;
}

void PmergeMe::sortDeque()
{
	std::clock_t start = std::clock();
	fjDeque(_deq);
	std::clock_t end = std::clock();
	_deqTime = static_cast<double>(end - start)
			/ static_cast<double>(CLOCKS_PER_SEC) * 1e6;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:33:56 by gansari           #+#    #+#             */
/*   Updated: 2026/03/09 15:34:43 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <algorithm>   // std::find, std::lower_bound
#include <climits>     // INT_MAX
#include <ctime>       // std::clock
#include <utility>     // std::pair, std::make_pair

PmergeMe::PmergeMe() : _vecTime(0.0), _deqTime(0.0) {}

PmergeMe::PmergeMe(const PmergeMe& o)
	: _vec(o._vec), _deq(o._deq),
	_vecTime(o._vecTime), _deqTime(o._deqTime) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& o)
{
	if (this != &o) {
		_vec     = o._vec;
		_deq     = o._deq;
		_vecTime = o._vecTime;
		_deqTime = o._deqTime;
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
	if (argc < 2)
		throw std::runtime_error("Error");

	for (int i = 1; i < argc; ++i)
	{
		std::string token(argv[i]);

		if (token.empty())
			throw std::runtime_error("Error");

		// Every character must be a digit (no sign, no dot)
		for (size_t c = 0; c < token.size(); ++c)
			if (!std::isdigit(static_cast<unsigned char>(token[c])))
				throw std::runtime_error("Error");

		// Convert — use long to detect int overflow
		long val = 0;
		for (size_t c = 0; c < token.size(); ++c)
		{
			val = val * 10 + (token[c] - '0');
			if (val > INT_MAX)
				throw std::runtime_error("Error");
		}

		if (val <= 0)
			throw std::runtime_error("Error");

		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
	}

	if (_vec.empty())
		throw std::runtime_error("Error");
}

// ─────────────────────────────────────────────────────────────────────────────
//  Jacobsthal insertion order
//
//  Generates the sequence of 1-based b-indices to insert after b1:
//    b3, b2, b5, b4, b11, b10, b9, b8, b7, b6, b21, ..., b12, ...
//
//  The Jacobsthal numbers (1-based): 1, 3, 5, 11, 21, 43, 85, ...
//  Each consecutive pair (J[k-1], J[k]) defines a group: insert from
//  min(J[k], n) down to J[k-1]+1.
// ─────────────────────────────────────────────────────────────────────────────

static std::vector<size_t> makeInsertOrder(size_t n)
{
	std::vector<size_t> order;
	if (n <= 1)
		return order;  // b1 is already inserted; nothing else to do for n==1

	// Build Jacobsthal sequence until it exceeds n
	std::vector<size_t> jac;
	jac.push_back(1);
	jac.push_back(3);
	while (jac.back() < n)
	{
		size_t next = jac.back() + 2 * jac[jac.size() - 2];
		jac.push_back(next);
	}
	// jac = {1, 3, 5, 11, 21, ...} with last element >= n

	for (size_t g = 1; g < jac.size(); ++g)
	{
		size_t hi = std::min(jac[g], n);   // clamp to actual pair count
		size_t lo = jac[g - 1] + 1;         // first index of this group
		if (lo > n) break;
		for (size_t i = hi; i >= lo; --i)   // insert high→low within group
			order.push_back(i);
	}
	return order;
}

// ─────────────────────────────────────────────────────────────────────────────
//  Ford-Johnson (merge-insert) sort — std::vector<int>
//
//  Steps:
//   1. If size <= 1: done.
//   2. If odd: save the last element as `straggler`.
//   3. Form pairs; within each pair sort so larger is first.
//   4. Recursively sort the sequence of larger elements (keeping pairs together).
//   5. Build main chain: [b1, a1, a2, ..., an] (b1 = smaller of first pair).
//   6. Insert remaining b's in Jacobsthal order using binary search,
//      bounded above by the current position of each b's partner a.
//   7. Insert straggler via binary search.
// ─────────────────────────────────────────────────────────────────────────────

void PmergeMe::fjVector(std::vector<int>& v)
{
	size_t n = v.size();
	if (n <= 1) return;

	// ── Step 2: straggler ────────────────────────────────────────────────────
	bool odd = (n % 2 != 0);
	int  straggler = 0;
	if (odd) { straggler = v.back(); v.pop_back(); n--; }

	size_t pc = n / 2;  // pair count

	// ── Step 3: form pairs (larger, smaller) ─────────────────────────────────
	std::vector<std::pair<int, int> > pairs(pc);
	for (size_t i = 0; i < pc; ++i)
	{
		int a = v[2 * i], b = v[2 * i + 1];
		pairs[i] = (a >= b) ? std::make_pair(a, b) : std::make_pair(b, a);
	}

	// ── Step 4: recursively sort the larger elements ──────────────────────────
	std::vector<int> largers;
	largers.reserve(pc);
	for (size_t i = 0; i < pc; ++i)
		largers.push_back(pairs[i].first);

	fjVector(largers);  // recursive call — largers is now sorted

	// Reconstruct pairs in the new sorted order.
	// We match each sorted larger value back to its pair using a used-flag array
	// to handle (the rare case of) equal larger values correctly.
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

	// ── Step 5: build main chain ──────────────────────────────────────────────
	// chain = [b1, a1, a2, ..., an]
	std::vector<int> chain;
	chain.reserve(n + 1);
	chain.push_back(pairs[0].second);            // b1
	for (size_t i = 0; i < pc; ++i)
		chain.push_back(pairs[i].first);         // a1 … an

	// Track the current index of each a_i inside chain.
	// Initially a_i is at position i+1 (b1 occupies position 0).
	std::vector<size_t> aPos(pc);
	for (size_t i = 0; i < pc; ++i)
		aPos[i] = i + 1;

	// ── Step 6: insert remaining b's in Jacobsthal order ─────────────────────
	std::vector<size_t> order = makeInsertOrder(pc);

	for (size_t k = 0; k < order.size(); ++k)
	{
		size_t idx = order[k] - 1;              // 0-based index into pairs
		int    val  = pairs[idx].second;         // b to insert
		size_t ubPos = aPos[idx];                // current position of its partner a

		// Binary search in [chain.begin(), chain.begin() + ubPos + 1)
		// i.e., only search up to and including the partner a's position.
		std::vector<int>::iterator beg = chain.begin();
		std::vector<int>::iterator ub  = beg + static_cast<long>(ubPos + 1);
		std::vector<int>::iterator pos = std::lower_bound(beg, ub, val);

		size_t insertIdx = static_cast<size_t>(pos - chain.begin());
		chain.insert(pos, val);

		// Shift aPos for all a's that are at or after the insertion point.
		for (size_t j = 0; j < pc; ++j)
			if (aPos[j] >= insertIdx)
				aPos[j]++;
	}

	// ── Step 7: insert straggler ──────────────────────────────────────────────
	if (odd)
	{
		std::vector<int>::iterator pos =
			std::lower_bound(chain.begin(), chain.end(), straggler);
		chain.insert(pos, straggler);
	}

	v = chain;
}

// ─────────────────────────────────────────────────────────────────────────────
//  Ford-Johnson sort — std::deque<int>
//  Identical algorithm; only the container type changes.
// ─────────────────────────────────────────────────────────────────────────────

void PmergeMe::fjDeque(std::deque<int>& d)
{
	size_t n = d.size();
	if (n <= 1) return;

	bool odd = (n % 2 != 0);
	int  straggler = 0;
	if (odd) { straggler = d.back(); d.pop_back(); n--; }

	size_t pc = n / 2;

	std::vector<std::pair<int, int> > pairs(pc);
	for (size_t i = 0; i < pc; ++i)
	{
		int a = d[2 * i], b = d[2 * i + 1];
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

// ─────────────────────────────────────────────────────────────────────────────
//  Public sort methods — time each container independently
// ─────────────────────────────────────────────────────────────────────────────

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
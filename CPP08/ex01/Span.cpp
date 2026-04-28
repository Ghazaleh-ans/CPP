/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:40:20 by gansari           #+#    #+#             */
/*   Updated: 2026/04/25 23:17:04 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm> // std::sort, std::min_element, std::max_element
#include <stdexcept>
#include <climits> // INT_MAX

Span::Span() {}

Span::Span(unsigned int N) : _maxSize(N)
{
	_data.reserve(N);
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _data(other._data) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_data = other._data;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_data.size() >= static_cast<size_t>(_maxSize))
		throw FullException();

	_data.push_back(n);
}

int Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw TooFewElementsException();

	std::vector<int> sorted(_data);
	std::sort(sorted.begin(), sorted.end());

	int shortest = INT_MAX;
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		int gap = sorted[i] - sorted[i - 1];
		if (gap < shortest)
			shortest = gap;
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (_data.size() < 2)
		throw TooFewElementsException();

	int minVal = *std::min_element(_data.begin(), _data.end());
	int maxVal = *std::max_element(_data.begin(), _data.end());

	return maxVal - minVal;
}

unsigned int Span::size() const
{
	return static_cast<unsigned int>(_data.size());
}

unsigned int Span::maxSize() const
{
	return _maxSize;
}
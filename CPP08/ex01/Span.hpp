/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:39:57 by gansari           #+#    #+#             */
/*   Updated: 2026/02/19 18:34:45 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>
#include <exception>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_data;

	Span();

public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	class FullException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Span is full: cannot add more numbers";
		}
	};

	class TooFewElementsException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Span needs at least 2 numbers to compute a span";
		}
	};

	class RangeOverflowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Span: addRange would exceed maximum capacity";
		}
	};

	void addNumber(int n);

	template <typename Iterator>
	void addRange(Iterator first, Iterator last)
	{
		unsigned int rangeSize = static_cast<unsigned int>(std::distance(first, last));
		if (_data.size() + rangeSize > _maxSize)
			throw RangeOverflowException();
		_data.insert(_data.end(), first, last);
	}

	int shortestSpan() const;
	int longestSpan() const;

	unsigned int size() const;
	unsigned int maxSize() const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:49:14 by gansari           #+#    #+#             */
/*   Updated: 2026/02/17 19:02:42 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T>
class Array
{
private:
	T*				_data;   // pointer to heap-allocated array
	unsigned int	_size;   // number of elements

public:
	Array() : _data(NULL), _size(0) {}
	Array(unsigned int n) : _data(new T[n]()), _size(n) {}
	Array(const Array& other) : _data(NULL), _size(0)
	{
		*this = other;
	}
	Array& operator=(const Array& other)
	{
		if (this == &other)
			return *this;
		delete[] _data;
		_data = NULL;
		_size = other._size;

		if (_size > 0)
		{
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = other._data[i];
		}
		return *this;
	}
	~Array()
	{
		delete[] _data;
	}
	T& operator[](unsigned int index)
	{
		if (index >= _size)
			throw std::out_of_range("Array index out of bounds");
		return _data[index];
	}
	const T& operator[](unsigned int index) const
	{
		if (index >= _size)
			throw std::out_of_range("Array index out of bounds");
		return _data[index];
	}
	unsigned int size() const
	{
		return _size;
	}
};

#endif
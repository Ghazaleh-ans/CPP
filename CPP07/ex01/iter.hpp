/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:24:03 by gansari           #+#    #+#             */
/*   Updated: 2026/02/17 17:57:18 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

// Overload 1: non-const array
template <typename T, typename F>
void iter(T* array, const std::size_t len, F func)
{
	for (std::size_t i = 0; i < len; ++i)
		func(array[i]);
}

// Overload 2: const array  (prevents modifying elements)
template <typename T, typename F>
void iter(const T* array, const std::size_t len, F func)
{
	for (std::size_t i = 0; i < len; ++i)
		func(array[i]);
}

#endif
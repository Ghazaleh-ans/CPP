/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:24:03 by gansari           #+#    #+#             */
/*   Updated: 2026/04/21 16:17:12 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

// non-const array
template <typename T, typename F>
void iter(T* array, const std::size_t len, F func)
{
	for (std::size_t i = 0; i < len; ++i)
		func(array[i]);
}

// const array
template <typename T, typename F>
void iter(const T* array, const std::size_t len, F func)
{
	for (std::size_t i = 0; i < len; ++i)
		func(array[i]);
}

#endif
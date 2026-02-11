/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:36:56 by gansari           #+#    #+#             */
/*   Updated: 2026/02/11 12:59:21 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
// Non-instantiable -> private
Serializer::Serializer() {
}

Serializer::Serializer(const Serializer& other) {
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
	(void)other;
	return *this;
}

Serializer::~Serializer() {
}

uintptr_t	Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
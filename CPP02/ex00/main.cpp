/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:14:15 by gansari           #+#    #+#             */
/*   Updated: 2025/09/05 13:29:15 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	Fixed d;

	d.setRawBits(42);
	std::cout << "d is " << d.getRawBits() << std::endl;
	Fixed e(d);
	std::cout << "e is " << e.getRawBits() << std::endl;
	Fixed f;
	f = e;
	std::cout << "f is " << f.getRawBits() << std::endl;
	std::cout << "a is " << a.getRawBits() << std::endl;
	std::cout << "b is " << b.getRawBits() << std::endl;
	std::cout << "c is " << c.getRawBits() << std::endl;
	std::cout << "d is " << d.getRawBits() << std::endl;
	std::cout << "e is " << e.getRawBits() << std::endl;
	std::cout << "f is " << f.getRawBits() << std::endl;
	a.setRawBits(1234);
	c = a;;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:35:58 by gansari           #+#    #+#             */
/*   Updated: 2025/09/03 13:17:04 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <level[DEBUG | INFO | WARNING | ERROR]>" << std::endl;
		return 1;
	}

	Harl harl;
	harl.complain(argv[1]);

	return 0;
}

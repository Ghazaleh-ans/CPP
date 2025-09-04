/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:25:37 by gansari           #+#    #+#             */
/*   Updated: 2025/09/03 12:35:58 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <string>
#include <fstream>
#include <iostream>

class FileReplacer
{
private:
	std::string _filename;
	std::string _s1;
	std::string _s2;
	std::string replaceAll(const std::string &line) const;
public:
	FileReplacer(const std::string &filename, const std::string &s1, const std::string &s2);
	~FileReplacer();
	bool process() const;
};

#endif

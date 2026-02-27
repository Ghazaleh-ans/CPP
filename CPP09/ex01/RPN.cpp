/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:54:37 by gansari           #+#    #+#             */
/*   Updated: 2026/02/27 15:11:27 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <sstream>
#include <stdexcept>

RPN::RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }
RPN::~RPN() {}

int RPN::applyOperator(char op, int left, int right)
{
	switch (op)
	{
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		case '/':
			if (right == 0)
				throw std::runtime_error("Error: division by zero.");
			return left / right;
		default:
			throw std::runtime_error("Error: unknown operator.");
	}
}

int RPN::evaluate(const std::string& expression) const
{
	if (expression.empty())
		throw std::runtime_error("Error: empty expression.");

	std::stack<int> stack;
	std::istringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (token.size() == 1 && std::isdigit(token[0]))
		{
			stack.push(token[0] - '0');
			continue;
		}

		if (token.size() == 1 && (token[0] == '+' || token[0] == '-'
								|| token[0] == '*' || token[0] == '/'))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: not enough operands.");

			int right = stack.top(); stack.pop();
			int left  = stack.top(); stack.pop();

			stack.push(applyOperator(token[0], left, right));
			continue;
		}

		throw std::runtime_error("Error: invalid token: " + token);
	}

	if (stack.empty())
		throw std::runtime_error("Error: empty expression.");
	if (stack.size() > 1)
		throw std::runtime_error("Error: too many operands.");

	return stack.top();
}
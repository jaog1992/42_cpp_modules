/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:09:18 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/31 18:31:18 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/**
 * @file RPN.cpp
 * @brief Implementation of a simple Reverse Polish Notation evaluator.
 *
 * The evaluator accepts space-separated tokens where operands are single
 * decimal digits and operators are `+ - * /`. Errors are reported via
 * exceptions (std::runtime_error) with descriptive messages.
 */

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
	// copy internal stack
	_stack = other._stack;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}

void	RPN::calculate(const char *argumento)
{
	std::stringstream ss(argumento);
	std::string token;

	while (ss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
		{
			_stack.push(token[0] - '0');
		}
		else if (token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos)
		{
			if (_stack.size() < 2)
			{
				throw std::runtime_error("Error: stack too low");
			}
			int op2 = _stack.top();
			_stack.pop();
			int op1 = _stack.top();
			_stack.pop();

			switch (token[0])
			{
				case '+':
					_stack.push(op1 + op2);
					break;
				case '-':
					_stack.push(op1 - op2);
					break;
				case '*':
					_stack.push(op1 * op2);
					break;
				case '/':
					if (op2 == 0)
						throw std::runtime_error("Error: division by zero");
					_stack.push(op1 / op2);
					break;
			}
		}
		else
		{
			throw std::runtime_error("Error: invalid input");
		}
	}
	if (_stack.size() != 1)
	{
		throw std::runtime_error("Error: invalid input");
	}

	std::cout << _stack.top() << std::endl;
}


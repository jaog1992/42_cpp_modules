/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:09:18 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/10 17:09:20 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "Default constructor called" << std::endl;
}

RPN::RPN(const RPN& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_stack = other._stack;
}

RPN& RPN::operator=(const RPN& other)
{
	std::cout << "Copy operator called" << std::endl;
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
	std::cout << "Destructor called" << std::endl;
}

void	RPN::calculate(const char *argumento)
{
	std::stringstream ss(argumento);
	std::string token;

	while (ss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
			_stack.push(token[0] - '0');
		else if (token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos)
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: stack too low");
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
			throw std::runtime_error("Error: invalid input");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: invalid input");
	std::cout << _stack.top() << std::endl;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:09:08 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/31 18:20:31 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "../incs/Colors.hpp"

/**
 * @file main.cpp
 * @brief Small driver for the RPN evaluator.
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: invalid argument." << RESET << std::endl;
		return (0);
	}

	try
	{
		RPN	operation;
		operation.calculate(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return (0);
}


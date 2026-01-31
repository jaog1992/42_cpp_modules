/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:09:47 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/31 18:41:46 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "../incs/Colors.hpp"

/**
 * @file main.cpp
 * @brief Driver for the PmergeMe program: parse input, run sorts and print timings.
 */

/**
 * @brief Print the contents of a vector to stdout separated by spaces.
 *
 * @param data The vector to print.
 */
void	printVector(const std::vector<int>& data)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	PmergeMe pmergeme;
	std::vector<int> vec;
	std::list<int> lst;

	if (!pmergeme.parser(argc, argv, vec, lst))
	{
		std::cerr << RED << "Error: invalid input" << RESET << std::endl;
		return (EXIT_FAILURE);
	}

	std::cout << "Before: ";
	printVector(vec);

	std::vector<int> vec_copy = vec;
	pmergeme.sortVector(vec);
	pmergeme.sortList(lst);
	
	std::cout << "After: ";
	printVector(vec);

	return (EXIT_SUCCESS);
}


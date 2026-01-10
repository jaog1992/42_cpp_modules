/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:09:47 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/10 17:09:51 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_container(const std::vector<int>& data)
{
	for (size_t i = 0; i < data.size(); i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	PmergeMe pmergeme;
	std::vector<int> vec;
	std::list<int> lst;

	if (!pmergeme.parse_and_validate(argc, argv, vec, lst))
	{
		std::cerr << "Error: invalid input" << std::endl;
		return (1);
	}

	std::cout << "Before: ";
	print_container(vec);

	std::vector<int> vec_copy = vec;
	pmergeme.sort_and_display_vector(vec);
	pmergeme.sort_and_display_list(lst);
	
	std::cout << "After: ";
	print_container(vec);

	return (0);
}


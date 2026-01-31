/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:53:27 by nquecedo          #+#    #+#             */
/*   Updated: 2026/01/31 18:47:41 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"
#include "../incs/Colors.hpp"
#include <iomanip>

/**
 * @file PmergeMe.cpp
 * @brief Implementation of the PmergeMe utilities (Ford–Johnson merge-insertion sort wrappers).
 *
 * This file contains the sort implementations and parsing helper used by the
 * `PmergeMe` program. Timing is printed to stdout; errors are reported by
 * returning false from `parser` (the caller prints an error message).
 */

void	PmergeMe::fordJohnsonSortVector(std::vector<int>& data)
{
	if (data.size() <= 1)
		return ;

	int 	odd_element = -1;
	bool	has_odd = data.size() % 2 != 0;
	if (has_odd)
	{
		odd_element = data.back();
		data.pop_back();
	}

	std::vector<int> losers;
	std::vector<int> winners;
	for (size_t i = 0; i < data.size(); i += 2)
	{
		if (data[i] < data[i + 1])
		{
			losers.push_back(data[i]);
			winners.push_back(data[i + 1]);
		}
		else
		{
			losers.push_back(data[i + 1]);
			winners.push_back(data[i]);
		}
	}

	fordJohnsonSortVector(losers);

	for (size_t i = 0; i < winners.size(); i++)
	{
		int to_insert = winners[i];
		size_t low = 0;
		size_t high = losers.size();

		while (low < high)
		{
			size_t mid = low + (high - low) /  2;
			if (losers[mid] < to_insert)
				low = mid + 1;
			else
				high = mid;
		}
		losers.insert(losers.begin() + low, to_insert);
	}

	if (has_odd)
	{
		int to_insert = odd_element;
		size_t low = 0;
		size_t high = losers.size();
		while (low < high)
		{
			size_t mid = low + (high - low) /  2;
			if (losers[mid] < to_insert)
				low = mid + 1;
			else
				high = mid;
		}
		losers.insert(losers.begin() + low, to_insert);
	}

	data = losers;
}

void	PmergeMe::fordJohnsonSortList(std::list<int>& data)
{
	if (data.size() <= 1)
		return;

	int 	odd_element = -1;
	bool	has_odd = data.size() % 2 != 0;
	if (has_odd)
	{
		odd_element = data.back();
		data.pop_back();
	}

	std::list<int> losers;
	std::list<int> winners;
	for (std::list<int>::iterator it = data.begin(); it != data.end(); )
	{
		int val1 = *it;
		it++;
		int val2 = *it;
		it++;
		if (val1 < val2)
		{
			losers.push_back(val1);
			winners.push_back(val2);
		}
		else
		{
			losers.push_back(val2);
			winners.push_back(val1);
		}
	}

	fordJohnsonSortList(losers);

	for (std::list<int>::iterator it_win = winners.begin(); it_win != winners.end(); ++it_win)
	{
		int to_insert = *it_win;
		std::list<int>::iterator it_los = losers.begin();
		while (it_los != losers.end() && *it_los < to_insert)
			it_los++;
		losers.insert(it_los, to_insert);
	}

	if (has_odd)
	{
		std::list<int>::iterator it = losers.begin();
		while (it != losers.end() && *it < odd_element)
			it++;
		losers.insert(it, odd_element);
	}

	data = losers;
}

void PmergeMe::sortVector(std::vector<int>& input_data)
{
	clock_t start = clock();
	fordJohnsonSortVector(input_data);
	clock_t end = clock();
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
	
	std::cout << "Time to process a range of " << input_data.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << elapsed_time << " us" << std::endl;
}

void PmergeMe::sortList(std::list<int>& input_data)
{
	clock_t start = clock();
	fordJohnsonSortList(input_data);
	clock_t end = clock();
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
	
	std::cout << "Time to process a range of " << input_data.size() << " elements with std::list : " << std::fixed << std::setprecision(5) << elapsed_time << " us" << std::endl;
}

bool	PmergeMe::parser(int argc, char **argv, std::vector<int>& vec, std::list<int>& lst)
{
	if (argc < 2)
	{
		return (false);
	}
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		if (arg.empty())
		{
			return (false);
		}

		for (size_t j = 0; j < arg.size(); ++j)
		{
			if (!std::isdigit(arg[j]))
				return (false);
		}

		std::stringstream ss(arg);
		int num;
		ss >> num;
		if (ss.fail() || num < 0)
			return (false);

		vec.push_back(num);
		lst.push_back(num);
	}
	return (true);
}


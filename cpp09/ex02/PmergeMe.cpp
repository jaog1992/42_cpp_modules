/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:53:27 by nquecedo          #+#    #+#             */
/*   Updated: 2026/02/01 10:31:06 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"
#include "../incs/Colors.hpp"
#include <iomanip>
#include <algorithm>
#include <vector>

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
		return;

	// Canonical Ford-Johnson (merge-insertion) implementation.
	// 1) Pair elements, keep winners (larger) and losers (smaller).
	// 2) Recursively sort winners.
	// 3) Insert losers into the sorted winners in the specific order
	//    determined by the Jacobsthal-based sequence to reduce comparisons.

	int odd_element = -1;
	bool has_odd = data.size() % 2 != 0;
	if (has_odd)
	{
		odd_element = data.back();
		data.pop_back();
	}

	std::vector<int> winners;
	std::vector<int> losers_vals;
	winners.reserve((data.size() + 1) / 2);
	losers_vals.reserve((data.size() + 1) / 2);

	for (size_t i = 0; i + 1 < data.size(); i += 2)
	{
		if (data[i] < data[i + 1])
		{
			losers_vals.push_back(data[i]);
			winners.push_back(data[i + 1]);
		}
		else
		{
			losers_vals.push_back(data[i + 1]);
			winners.push_back(data[i]);
		}
	}

	// Recursively sort winners using the same algorithm
	fordJohnsonSortVector(winners);

	// Pre-allocate final container size to avoid reallocation churn
	std::vector<int> merged = winners;
	merged.reserve(winners.size() + losers_vals.size() + (has_odd ? 1 : 0));

	// Build insertion order for losers using Jacobsthal-like sequence:
	// 0, 1, 3, 2, 6, 5, 4, ... (append blocks of [2^k-1 .. 2^(k-1)])
	std::vector<size_t> insertOrder;
	size_t t = losers_vals.size();
	if (t > 0)
	{
		insertOrder.push_back(0);
		for (int k = 1; insertOrder.size() < t; ++k)
		{
			int start = (1 << k) - 1;
			int end = (1 << (k - 1));
			for (int j = start; j >= end && insertOrder.size() < t; --j)
			{
				if ((size_t)j < t)
					insertOrder.push_back((size_t)j);
			}
		}
	}

	// Insert losers in the computed order using binary search (lower_bound)
	for (size_t idx = 0; idx < insertOrder.size(); ++idx)
	{
		int val = losers_vals[insertOrder[idx]];
		std::vector<int>::iterator it = std::lower_bound(merged.begin(), merged.end(), val);
		merged.insert(it, val);
	}

	// Finally insert the odd element if present
	if (has_odd)
	{
		std::vector<int>::iterator it = std::lower_bound(merged.begin(), merged.end(), odd_element);
		merged.insert(it, odd_element);
	}

	data.swap(merged);
}

void	PmergeMe::fordJohnsonSortList(std::list<int>& data)
{
	if (data.size() <= 1)
		return;

	// Canonical Ford-Johnson implementation for std::list.
	int odd_element = -1;
	bool has_odd = data.size() % 2 != 0;
	if (has_odd)
	{
		odd_element = data.back();
		data.pop_back();
	}

	// Extract winners and losers values into vectors to build the insertion order
	std::vector<int> winners_vals;
	std::vector<int> losers_vals;
	winners_vals.reserve((data.size() + 1) / 2);
	losers_vals.reserve((data.size() + 1) / 2);

	for (std::list<int>::iterator it = data.begin(); it != data.end(); )
	{
		int val1 = *it; ++it;
		int val2 = *it; ++it;
		if (val1 < val2)
		{
			losers_vals.push_back(val1);
			winners_vals.push_back(val2);
		}
		else
		{
			losers_vals.push_back(val2);
			winners_vals.push_back(val1);
		}
	}

	// Build a list from winners_vals and sort it recursively
	std::list<int> winners_list;
	for (size_t i = 0; i < winners_vals.size(); ++i)
		winners_list.push_back(winners_vals[i]);

	fordJohnsonSortList(winners_list);

	// Build insertion order for losers (Jacobsthal-like sequence)
	std::vector<size_t> insertOrder;
	size_t t = losers_vals.size();
	if (t > 0)
	{
		insertOrder.push_back(0);
		for (int k = 1; insertOrder.size() < t; ++k)
		{
			int start = (1 << k) - 1;
			int end = (1 << (k - 1));
			for (int j = start; j >= end && insertOrder.size() < t; --j)
			{
				if ((size_t)j < t)
					insertOrder.push_back((size_t)j);
			}
		}
	}

	// Insert losers into winners_list following the computed order
	for (size_t idx = 0; idx < insertOrder.size(); ++idx)
	{
		int val = losers_vals[insertOrder[idx]];
		std::list<int>::iterator it = winners_list.begin();
		while (it != winners_list.end() && *it < val)
			++it;
		winners_list.insert(it, val);
	}

	// Finally insert odd element if present
	if (has_odd)
	{
		std::list<int>::iterator it = winners_list.begin();
		while (it != winners_list.end() && *it < odd_element)
			++it;
		winners_list.insert(it, odd_element);
	}

	data.swap(winners_list);
}

double PmergeMe::sortVector(std::vector<int>& input_data)
{
	clock_t start = clock();
	fordJohnsonSortVector(input_data);
	clock_t end = clock();
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
	return elapsed_time;
}

double PmergeMe::sortList(std::list<int>& input_data)
{
	clock_t start = clock();
	fordJohnsonSortList(input_data);
	clock_t end = clock();
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
	return elapsed_time;
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


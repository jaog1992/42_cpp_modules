/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:09:47 by jde-orma          #+#    #+#             */
/*   Updated: 2026/02/01 11:56:37 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "../incs/Colors.hpp"
#include <iomanip>
#include <algorithm>

// Recursive demo helper: sort a sequence using the same pair->winners recursion
// and show intermediate groupings. Returns a sorted vector.
/*
static std::vector<int> demoRecursiveSort(std::vector<int> seq, int level = 2)
{
	// base case
	if (seq.size() <= 1)
		return seq;

	int odd = -1;
	if (seq.size() % 2 != 0)
	{
		odd = seq.back();
		seq.pop_back();
	}

	// Pairing for this level
	std::vector<int> winners;
	std::vector<int> losers;
	std::vector< std::pair<int,int> > pairs;
	for (size_t i = 0; i + 1 < seq.size(); i += 2)
	{
		int a = seq[i];
		int b = seq[i+1];
		int w = (a < b ? b : a);
		int l = (a < b ? a : b);
		winners.push_back(w);
		losers.push_back(l);
		pairs.push_back(std::make_pair(a,b));
	}

	// Print groups for this level
	std::cout << MAGENTA << "Level " << level << " Winners Groups (size 2): " << RESET;
	const char* colors[] = {BLUE, CYAN, MAGENTA, GREEN, YELLOW, RED};
	const size_t ncolors = sizeof(colors) / sizeof(colors[0]);
	for (size_t p = 0; p < pairs.size(); ++p)
	{
		const char* col = colors[p % ncolors];
		std::cout << col << "[ " << pairs[p].first << " " << pairs[p].second << " ] " << RESET;
	}
	if (seq.size() % 2 != 0)
		std::cout << YELLOW << "[ " << odd << " ]" << RESET;
	std::cout << std::endl;

	// Print winners and losers arrays for this level
	std::cout << "Level " << level << " Winners: ";
	std::cout << GREEN << "[ ";
	for (size_t i = 0; i < winners.size(); ++i)
		std::cout << winners[i] << (i + 1 < winners.size() ? " " : " ");
	std::cout << "]" << RESET << std::endl;

	std::cout << "Level " << level << " Losers: ";
	std::cout << CYAN << "[ ";
	for (size_t i = 0; i < losers.size(); ++i)
		std::cout << losers[i] << (i + 1 < losers.size() ? " " : " ");
	std::cout << "]" << RESET << std::endl;

	// Recursively sort winners
	std::vector<int> winners_sorted;
	if (winners.size() > 1)
		winners_sorted = demoRecursiveSort(winners, level + 1);
	else
		winners_sorted = winners;

	// After recursion, show winners_sorted
	std::cout << GREEN << "Winners list (after recursive sort): ";
	for (size_t i = 0; i < winners_sorted.size(); ++i)
		std::cout << winners_sorted[i] << (i + 1 < winners_sorted.size() ? " " : "\n");
	std::cout << RESET;

	// Reinsert losers for THIS level using Jacobsthal order and print steps
	size_t t = losers.size();
	std::vector<size_t> order;
	if (t > 0)
	{
		order.push_back(0);
		for (int k = 1; order.size() < t; ++k)
		{
			int start = (1 << k) - 1;
			int end = (1 << (k - 1));
			for (int j = start; j >= end && order.size() < t; --j)
				if ((size_t)j < t) order.push_back((size_t)j);
		}
	}

	std::cout << "Losers before Jacobsthal: ";
	std::cout << CYAN << "[ ";
	for (size_t ii = 0; ii < losers.size(); ++ii)
		std::cout << losers[ii] << (ii + 1 < losers.size() ? " " : " ");
	std::cout << "]" << RESET << std::endl;

	std::cout << "Jacobsthal insertion order (index 2^k - 1 to 2^(k-1)): " << MAGENTA;
	for (size_t idx = 0; idx < order.size(); ++idx)
		std::cout << order[idx] << (idx + 1 < order.size() ? " " : "\n");
	std::cout << RESET;

	// Losers reordered by Jacobsthal indices
	std::vector<int> losers_after;
	losers_after.reserve(order.size());
	for (size_t ii = 0; ii < order.size(); ++ii)
		losers_after.push_back(losers[order[ii]]);

	std::cout << "Losers after Jacobsthal: ";
	std::cout << CYAN << "[ ";
	for (size_t ii = 0; ii < losers_after.size(); ++ii)
		std::cout << losers_after[ii] << (ii + 1 < losers_after.size() ? " " : " ");
	std::cout << "]" << RESET << std::endl;

	std::vector<int> merged = winners_sorted;
	for (size_t step = 0; step < order.size(); ++step)
	{
		size_t loser_idx = order[step];
		int val = losers[loser_idx];
		std::vector<int>::iterator it = std::lower_bound(merged.begin(), merged.end(), val);
		size_t pos = it - merged.begin();
		merged.insert(it, val);

		std::cout << "Insertion " << (step + 1) << " | Jacobsthal index " << MAGENTA << loser_idx << RESET << " | insert pos " << pos << ": ";
		for (size_t m = 0; m < merged.size(); ++m)
		{
			if (m == pos)
				std::cout << YELLOW << merged[m] << RESET;
			else
				std::cout << merged[m];
			std::cout << (m + 1 < merged.size() ? " " : "\n");
		}
	}

	// Insert odd leftover if present
	if (odd != -1)
	{
		std::vector<int>::iterator it = std::lower_bound(merged.begin(), merged.end(), odd);
		size_t pos = it - merged.begin();
		merged.insert(it, odd);
		std::cout << "Insertion (leftover) | value " << YELLOW << odd << RESET << " | insert pos " << pos << ": ";
		for (size_t m = 0; m < merged.size(); ++m)
		{
			if (m == pos)
				std::cout << YELLOW << merged[m] << RESET;
			else
				std::cout << merged[m];
			std::cout << (m + 1 < merged.size() ? " " : "\n");
		}
	}

	std::cout << MAGENTA << "End of level " << level << "\n" << RESET;
	return merged;
}

// Demo helper: muestra paso a paso el emparejado/agrupado y la secuencia Jacobsthal
// Funciona con secuencias de hasta 36 enteros y usa colores para las parejas/grupos.
static void demoFordJohnson(const std::vector<int>& input)
{
	if (input.empty())
	{
		std::cout << YELLOW << "[Demo] input empty" << RESET << std::endl;
		return;
	}
	if (input.size() > 36)
	{
		std::cout << YELLOW << "[Demo] input too large (max 36)" << RESET << std::endl;
		return;
	}

	const char* colors[] = {BLUE, CYAN, MAGENTA, GREEN, YELLOW, RED};
	const size_t ncolors = sizeof(colors) / sizeof(colors[0]);

	std::cout << MAGENTA << "[Demo] Ford-Johnson step-by-step" << RESET << std::endl;
	std::cout << "Input: ";
	for (size_t i = 0; i < input.size(); ++i) std::cout << input[i] << (i + 1 < input.size() ? " " : "\n");

	// Level 1: pairs -> prepare groups, winners, losers
	std::vector< std::vector<int> > groups;
	size_t idx = 0;
	while (idx + 1 < input.size())
	{
		groups.push_back(std::vector<int>());
		groups.back().push_back(input[idx]);
		groups.back().push_back(input[idx+1]);
		idx += 2;
	}
	if (idx < input.size()) // leftover
		groups.push_back(std::vector<int>(1, input[idx]));

	// Build winners and losers lists from the pairs (for didactic display)
	std::vector<int> winners;
	std::vector<int> losers_vals;
	for (size_t j = 0; j + 1 < input.size(); j += 2)
	{
		int a = input[j];
		int b = input[j+1];
		winners.push_back(std::max(a, b));
		losers_vals.push_back(std::min(a, b));
	}

	// Start ordering winners
	std::cout << MAGENTA << "Ordering winner list" << RESET << std::endl;

	// Level 1 groups
	std::cout << MAGENTA << "Level 1 Winners Groups (size 2): " << RESET;
	for (size_t g = 0; g < groups.size(); ++g)
	{
		const char* col = colors[g % ncolors];
		std::cout << col << "[ ";
		for (size_t x = 0; x < groups[g].size(); ++x)
		{
			std::cout << groups[g][x] << (x + 1 < groups[g].size() ? " " : " ");
		}
		std::cout << "] " << RESET;
	}
	std::cout << std::endl;

	std::cout << "Level 1 Winners: ";
	std::cout << GREEN << "[ ";
	for (size_t wi = 0; wi < winners.size(); ++wi)
		std::cout << winners[wi] << (wi + 1 < winners.size() ? " " : " ");
	std::cout << "]" << RESET << std::endl;

	std::cout << "Level 1 Losers: ";
	std::cout << CYAN << "[ ";
	for (size_t li = 0; li < losers_vals.size(); ++li)
		std::cout << losers_vals[li] << (li + 1 < losers_vals.size() ? " " : " ");
	std::cout << "]" << RESET << std::endl;

	// Recursively sort winners (levels >= 2 will be shown by demoRecursiveSort)
	std::vector<int> merged = winners;
	if (winners.size() > 1)
		merged = demoRecursiveSort(winners, 2);

	// After recursive ordering of winners, show merged winners
	std::cout << GREEN << "Winners list (after recursive sort): ";
	for (size_t z = 0; z < merged.size(); ++z)
		std::cout << merged[z] << (z + 1 < merged.size() ? " " : "\n");
	std::cout << RESET;

	// For the top-level losers (from original pairs), compute Jacobsthal insert order and insert now
	std::vector<int> top_losers = losers_vals;
	size_t t = top_losers.size();
	std::vector<size_t> insertOrder;
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

	std::cout << "Losers before Jacobsthal: ";
	std::cout << CYAN << "[ ";
	for (size_t ii = 0; ii < top_losers.size(); ++ii)
		std::cout << top_losers[ii] << (ii + 1 < top_losers.size() ? " " : " ");
	std::cout << "]" << RESET << std::endl;

	std::cout << "Jacobsthal insertion order (index 2^k - 1 to 2^(k-1)): " << MAGENTA;
	for (size_t idx2 = 0; idx2 < insertOrder.size(); ++idx2)
		std::cout << insertOrder[idx2] << (idx2 + 1 < insertOrder.size() ? " " : "\n");
	std::cout << RESET;

	std::vector<int> top_losers_after;
	top_losers_after.reserve(insertOrder.size());
	for (size_t ii = 0; ii < insertOrder.size(); ++ii)
		top_losers_after.push_back(top_losers[insertOrder[ii]]);

	std::cout << "Losers after Jacobsthal: ";
	std::cout << CYAN << "[ ";
	for (size_t ii = 0; ii < top_losers_after.size(); ++ii)
		std::cout << top_losers_after[ii] << (ii + 1 < top_losers_after.size() ? " " : " ");
	std::cout << "]" << RESET << std::endl;

	for (size_t step = 0; step < insertOrder.size(); ++step)
	{
		size_t loser_idx = insertOrder[step];
		int val = top_losers[loser_idx];
		std::vector<int>::iterator it = std::lower_bound(merged.begin(), merged.end(), val);
		size_t pos = it - merged.begin();
		merged.insert(it, val);

		std::cout << "Insertion " << (step + 1) << " | Jacobsthal index " << MAGENTA << loser_idx << RESET << " | insert pos " << pos << ": ";
		for (size_t m = 0; m < merged.size(); ++m)
		{
			if (m == pos)
				std::cout << YELLOW << merged[m] << RESET;
			else
				std::cout << merged[m];
			std::cout << (m + 1 < merged.size() ? " " : "\n");
		}
	}

	// Finally insert odd element if present
	if (input.size() % 2 != 0)
	{
		int odd = input.back();
		std::vector<int>::iterator it = std::lower_bound(merged.begin(), merged.end(), odd);
		size_t pos = it - merged.begin();
		merged.insert(it, odd);
		std::cout << "Insertion (leftover) | value " << YELLOW << odd << RESET << " | insert pos " << pos << ": ";
		for (size_t m = 0; m < merged.size(); ++m)
		{
			if (m == pos)
				std::cout << YELLOW << merged[m] << RESET;
			else
				std::cout << merged[m];
			std::cout << (m + 1 < merged.size() ? " " : "\n");
		}
	}

	std::cout << MAGENTA << "End of level 1" << RESET << std::endl;
}
*/

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

	double time_vec = pmergeme.sortVector(vec);
	double time_lst = pmergeme.sortList(lst);

	// Validate that both containers are correctly sorted
	if (!isSorted(vec) || !isSorted(lst))
	{
		std::cerr << RED << "Error: sorting failed (sequence not ordered)" << RESET << std::endl;
		return (EXIT_FAILURE);
	}

	std::cout << "After: ";
	printVector(vec);

	// Print timings as in the subject example
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << lst.size() << " elements with std::list : " << std::fixed << std::setprecision(5) << time_lst << " us" << std::endl;

	return (EXIT_SUCCESS);
}
/*
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

	// Demo: muestra paso a paso el Ford-Johnson. Descomenta para ejecutarlo.
	demoFordJohnson(vec);

	double time_vec = pmergeme.sortVector(vec);

	// Validate that both containers are correctly sorted
	if (!isSorted(vec))
	{
		std::cerr << RED << "Error: sorting failed (sequence not ordered)" << RESET << std::endl;
		return (EXIT_FAILURE);
	}

	std::cout << "After: ";
	printVector(vec);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << time_vec << " us" << std::endl;

	return (EXIT_SUCCESS);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:53:27 by nquecedo          #+#    #+#             */
/*   Updated: 2025/12/23 03:05:09 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

void	PmergeMe::ford_johnson_sort_vector(std::vector<int>& data)
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

	ford_johnson_sort_vector(losers);

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

void	PmergeMe::ford_johnson_sort_list(std::list<int>& data)
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

	ford_johnson_sort_list(losers);

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

void PmergeMe::sort_and_display_vector(std::vector<int>& input_data)
{
	clock_t start = clock();
	ford_johnson_sort_vector(input_data);
	clock_t end = clock();
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
	
	std::cout << "Time to process a range of " << input_data.size() << " elements with std::vector : " << elapsed_time << " us" << std::endl;
}

void PmergeMe::sort_and_display_list(std::list<int>& input_data)
{
	clock_t start = clock();
	ford_johnson_sort_list(input_data);
	clock_t end = clock();
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
	
	std::cout << "Time to process a range of " << input_data.size() << " elements with std::list : " << elapsed_time << " us" << std::endl;
}

bool	PmergeMe::parse_and_validate(int argc, char **argv, std::vector<int>& vec, std::list<int>& lst)
{
	if (argc < 2)
		return (false);
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		if (arg.empty())
			return (false);

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


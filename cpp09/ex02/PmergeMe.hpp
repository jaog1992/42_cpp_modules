/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:53:27 by nquecedo          #+#    #+#             */
/*   Updated: 2026/02/01 10:29:26 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <sys/time.h>

// Helper: comprobación de orden (C++98-compatible)
template <typename Iter>
bool isSorted(Iter first, Iter last)
{
	if (first == last)
		return true;
	Iter next = first;
	++next;
	for (; next != last; ++first, ++next)
	{
		if (*next < *first)
			return false;
	}
	return true;
}

template <typename Container>
bool isSorted(const Container& c)
{
	return isSorted(c.begin(), c.end());
}

class PmergeMe
{
	private:
		void	fordJohnsonSortVector(std::vector<int>& data);
		void	fordJohnsonSortList(std::list<int>& data);

	public:
		double	sortVector(std::vector<int>& input_data);
		double	sortList(std::list<int>& input_data);

		bool	parser(int argc, char **argv, std::vector<int>& vec, std::list<int>& lst);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:53:27 by nquecedo          #+#    #+#             */
/*   Updated: 2026/01/31 18:38:01 by jde-orma         ###   ########.fr       */
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

class PmergeMe
{
	private:
		/**
		 * @brief Perform Ford–Johnson (merge-insertion) sort on a vector.
		 *
		 * Internal helper used by `sortVector`. Sorts `data` in-place.
		 *
		 * @param data Vector of integers to sort.
		 */
		void	fordJohnsonSortVector(std::vector<int>& data);

		/**
		 * @brief Perform Ford–Johnson (merge-insertion) sort on a list.
		 *
		 * Internal helper used by `sortList`. Sorts `data` in-place.
		 *
		 * @param data List of integers to sort.
		 */
		void	fordJohnsonSortList(std::list<int>& data);

	public:
		/**
		 * @brief Sort a vector using the Ford–Johnson algorithm wrapper.
		 *
		 * Measures the time taken and prints a timing line.
		 *
		 * @param input_data Vector to sort in-place.
		 */
		void	sortVector(std::vector<int>& input_data);

		/**
		 * @brief Sort a list using the Ford–Johnson algorithm wrapper.
		 *
		 * Measures the time taken and prints a timing line.
		 *
		 * @param input_data List to sort in-place.
		 */
		void	sortList(std::list<int>& input_data);

		/**
		 * @brief Parse command-line arguments into integer containers.
		 *
		 * Validates that each argv entry is a non-negative integer and fills
		 * the provided `vec` and `lst` containers with the parsed values.
		 *
		 * @param argc Argument count from `main`.
		 * @param argv Argument vector from `main`.
		 * @param vec Output vector to fill with integers.
		 * @param lst Output list to fill with integers.
		 * @return `true` on successful parse, `false` on invalid input.
		 */
		bool	parser(int argc, char **argv, std::vector<int>& vec, std::list<int>& lst);
};

#endif

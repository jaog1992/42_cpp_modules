/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:53:27 by nquecedo          #+#    #+#             */
/*   Updated: 2025/12/23 02:59:55 by nquecedo         ###   ########.fr       */
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
		void	ford_johnson_sort_vector(std::vector<int>& data);
		void	ford_johnson_sort_list(std::list<int>& data);

	public:
		void	sort_and_display_vector(std::vector<int>& input_data);
		void	sort_and_display_list(std::list<int>& input_data);

		bool	parse_and_validate(int argc, char **argv, std::vector<int>& vec, std::list<int>& lst);
};

#endif

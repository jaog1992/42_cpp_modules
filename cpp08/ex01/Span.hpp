/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:54:14 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/10 18:25:47 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP

# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>
# include <climits>
# include <iostream>


typedef std::vector<int>::iterator	VectorIt;

/**
 * @class Span
 * @brief A class for storing integers and calculating the shortest and longest spans.
 *
 * The Span class allows the user to store a collection of integers up to a specified maximum size
 * and provides methods to calculate the shortest and longest spans between the stored integers.
 */
class Span {
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span( unsigned int num );
		Span( const Span &other );
		Span & operator=( const Span &other );
		~Span( void );

		void	addNumber( int num );
    	template <typename It>
		void addSequence(It start, It end) {
		    if (_numbers.size() + std::distance(start, end) > _maxSize)
		        throw std::out_of_range("Error: The container is full.");
		    _numbers.insert(_numbers.end(), start, end);
		}

		void printVector() const {
		    for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); ++it)
		        std::cout << *it << " ";
		    std::cout << std::endl;
		}

		int		shortestSpan( void ) const;
		int		longestSpan( void ) const;

		const std::vector<int> &getNumbers() const { return _numbers; }
};

#endif

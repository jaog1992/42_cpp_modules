/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:54:14 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/04 18:54:16 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP

# define SPAN_HPP

# include "../incs/Colors.hpp"

# include <iostream>
# include <vector>
# include <stdexcept>
# include <algorithm>
# include <climits>

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
		unsigned int		_maxSize;///< The maximum number of integers that can be stored
		std::vector<int>	_numbers;///< The container storing the integers.

	public:
		Span( void );
		Span( unsigned int maxSize );
		Span( const Span &oneSpan );
		Span & operator=( const Span &oneSpan );
		~Span( void );

		const unsigned int	&getN( void ) const;
		void				setN( unsigned int maxSize );

		void	addNumber( int nbr );
		void	addSequence( VectorIt start, VectorIt end );
		int		shortestSpan( void );
		int		longestSpan( void );
		void	printVector( void );
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:53:43 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/10 18:28:44 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/**
 * @brief Construct a new Span object with the values passed as parameters.
 *
 * @param num The maximum number of integers the Span object can store
 */
Span::Span( unsigned int num ) : _maxSize(num) {
}

/**
 * @brief Construct a new Span object by copying the values from another object.
 *
 * @param other A reference to the Span object to be copied.
 */
Span::Span( const Span &other ) : _maxSize(other._maxSize), _numbers(other._numbers) {
}

/**
 * @brief Destroy the Span object.
 */
Span::~Span( void ) {
}

/**
 * @brief Overloads the assignment operator for the Span class.
 *
 * @param other The source Span object to assign from.
 * @return Span& A reference to the current Span object after assignment.
 */
Span & Span::operator=( const Span &other ) {
	if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
	}
	return *this;
}

/**
 * @brief Adds a number to the vector of Span object.
 *
 * @param num The integer to add to the container.
 * @throw std::out_of_range if the container is already full..
 */
void	Span::addNumber( int num ) {
	if (_numbers.size() == _maxSize) {
		throw std::out_of_range("Error: The container is full.");
	}
	_numbers.push_back(num);
}

/**
 * @brief Calculates the shortest span between any two numbers in the Span object.
 *
 * Finds the smallest difference between any two consecutive numbers in the sorted container.
 *
 * @return int The shortest span between any two numbers.
 * @throw std::length_error if there are less than two numbers in the container.
 */
int	Span::shortestSpan( void ) const {
	if (_numbers.size() < 2) {
		throw std::length_error("Error: Not enough numbers to find a span.");
	}
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

	int	min_span = INT_MAX;
	for (int i = 1; i < (int)tmp.size(); i++) {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < min_span)
            min_span = diff;
	}
	return min_span;
}

/**
 * @brief Calculates the longest span between the minimum and maximum numbers in the vector of Span object.
 *
 * @return int The longest span between the smallest and largest numbers.
 */
int	Span::longestSpan( void ) const{
	if (_numbers.size() < 2)
        throw std::length_error("Not enough numbers for a span");
	return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:05:03 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/04 18:12:45 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Iter.hpp
 * @brief Template function to apply a given function to each element of an array.
 * 
 *  The function is templated to work with any type of array and function.
 * 
 */

#ifndef ITER_HPP

# define ITER_HPP

# include <cstddef>

/**
 * @brief Applies a function to each element of an array.
 * 
 * This template function iterates over an array and applies a provided function 
 * to each element of the array. It is designed to work with arrays of any type and 
 * function objects that operate on the elements of the array.
 * 
 * @tparam T The type of elements in the array.
 * @tparam F The type of the function to be applied to each element.
 * @param array A pointer to the first element of the array.
 * @param size The number of elements in the array.
 * @param function The function to apply to each element of the array.
 */
template <typename T, typename F>
void	iter( T *array, std::size_t size, F function ) {
	for (std::size_t i = 0; i < size; i++) {
		function(array[i]);
	}
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:06:26 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/31 18:07:08 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP

# define FUNCTIONS_HPP

/**
 * @file Functions.hpp
 * @brief Template functions for swapping values and finding min/max.
 * 
 * This header defines three template functions:
 * - `swap`: Swaps the values of two variables.
 * - `min`: Returns the smaller of two values.
 * - `max`: Returns the larger of two values.
 * 
 */
template <typename T>
void	swap( T &val1, T &val2 ) {
	T	tmp = val1;
	val1 = val2;
	val2 = tmp;
}

/**
 * @brief Returns the smaller of the two values.
 * 
 * @tparam T The type of the variables to compare.
 * @param val1 The first value.
 * @param val2 The second value.
 * @return T The smaller of the two values.
 */
template <typename T>
T	min( T val1, T val2 ) {
	if (val1 < val2) {
		return val1;
	}
	return val2;
}

/**
 * @brief Returns the larger of the two values.
 * 
 * @tparam T The type of the variables to compare.
 * @param val1 The first value.
 * @param val2 The second value.
 * @return T The larger of the two values.
 */
template <typename T>
T	max( T val1, T val2 ) {
	if (val1 > val2) {
		return val1;
	}
	return val2;
}

#endif
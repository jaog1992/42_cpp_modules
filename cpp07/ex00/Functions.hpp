/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:06:26 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/10 15:38:55 by jde-orma         ###   ########.fr       */
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
void	swap( T &x, T &y ) {
	T	tmp = x;
	x = y;
	y = tmp;
}

/**
 * @brief Returns the smaller of the two values.
 * 
 * @tparam T The type of the variables to compare.
 * @param x The first value.
 * @param y The second value.
 * @return T The smaller of the two values.
 */
template <typename T>
T	min( T x, T y ) {
	return (x < y) ? x : y;
}

/**
 * @brief Returns the larger of the two values.
 * 
 * @tparam T The type of the variables to compare.
 * @param x The first value.
 * @param y The second value.
 * @return T The larger of the two values.
 */
template <typename T>
T	max( T x, T y ) {
	return (x > y) ? x : y;
}

#endif
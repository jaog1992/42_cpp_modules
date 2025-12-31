/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:20:17 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/31 11:52:09 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP

# define UTILS_HPP

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include "Base.hpp"
# include <stdlib.h>
# include <ctime>

/**
 * @brief Randomly create and return an instance of A, B or C.
 *
 * @return Base* Pointer to a newly allocated object of type A, B, or C.
 */
Base * generate( void );

/**
 * @brief Identify the dynamic type of a Base reference and print it.
 *
 * Uses dynamic_cast with references and exception handling to detect the
 * concrete derived type and prints 'A', 'B', or 'C'.
 *
 * @param p Reference to a Base-derived instance.
 */
void	identify( Base &p );

/**
 * @brief Identify the dynamic type of a Base pointer and print it.
 *
 * Uses dynamic_cast on pointers to determine the concrete type and prints
 * 'A', 'B', or 'C'.
 *
 * @param p Pointer to a Base-derived instance.
 */
void	identify( Base *p );

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:07:55 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/04 18:48:50 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP

# define ARRAY_HPP

#include <cstddef>

template <typename T>
class Array {
	private:
		T*			_data;
		std::size_t	_size;

	public:
		Array( void );
        Array( unsigned int size );
        Array( const Array &otherArray );

        ~Array( void );

        Array & operator=( const Array &otherArray );

        T& operator[](unsigned int index);

        unsigned int size() const;
};

# include "Array.tpp"

/**
 * @class Array
 * @brief Simple templated dynamic array with bounds-checked access.
 *
 * Implements a minimal dynamic array supporting default construction,
 * construction with size, copy construction, assignment, index access
 * and size query. Throws `std::out_of_range` when accessing an invalid index.
 *
 * @tparam T Type of elements stored in the array.
 */

#endif

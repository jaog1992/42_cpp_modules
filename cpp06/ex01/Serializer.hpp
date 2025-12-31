/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:18:39 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/31 11:52:06 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP

# define SERIALIZER_HPP

# include "../incs/Colors.hpp"
# include "Data.h"
# include <string>
# include <iostream>
# include <stdint.h>

class Serializer {
	private:
		/**
		 * @brief Private default constructor to prevent instantiation.
		 */
		Serializer( void );
		/**
		 * @brief Private copy constructor.
		 */
		Serializer( const Serializer &otherSerialize );
		/**
		 * @brief Private assignment operator.
		 */
		Serializer & operator=( const Serializer &otherSerialize );
		/**
		 * @brief Private destructor.
		 */
		~Serializer( void );

	public:
		/**
		 * @brief Serialize a Data* pointer to an integer representation.
		 *
		 * @param ptr Pointer to a Data structure to serialize.
		 * @return uintptr_t Integer representation of the pointer value.
		 */
		static uintptr_t serialize( Data* ptr );
		/**
		 * @brief Deserialize an integer back into a Data* pointer.
		 *
		 * @param raw Integer representation previously produced by serialize().
		 * @return Data* Restored pointer to Data (reinterpret_cast).
		 */
		static Data* deserialize( uintptr_t raw );
};

#endif
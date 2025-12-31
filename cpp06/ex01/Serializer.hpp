/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:18:39 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/31 15:55:03 by jde-orma         ###   ########.fr       */
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

		Serializer( void );
		Serializer( const Serializer &otherSerialize );
		Serializer & operator=( const Serializer &otherSerialize );
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
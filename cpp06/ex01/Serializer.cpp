/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:17:19 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/31 15:57:22 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/**
 * @brief  Default constructor for Serializer.
 * This class is intended to be non-instantiable by users; the constructor
 * is private to enforce static-only usage. The printed message is diagnostic.
 */
Serializer::Serializer( void ) {
	std::cout << GREEN << "Serializer default constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new Serializer object by copying the values from another object.
 *
 * @param otherSerializer A reference to the Serializer object to be copied.
 */
Serializer::Serializer( const Serializer &otherSerialize ) {
	*this = otherSerialize;
	std::cout << GREEN << "Serializer copy constructor called" << RESET << std::endl;
}

/**
 * @brief Overloaded assignment operator for Serializer class.
 * 
 * @param otherSerializer The source Serializer object to assign from.
 * @return Serializer& A reference to the current Serializer object after assignment.
 */
Serializer & Serializer::operator=( const Serializer &otherSerialize ) {
	if (this != &otherSerialize) {

	}
	return *this;
}

/**
 * @brief Destroy the Serializer object.
 */
Serializer::~Serializer( void ) {
	std::cout << RED << "Serializer destructor called" << RESET << std::endl;
}

/**
 * @brief Serialize a Data* pointer to an integer representation.
 *
 * Uses reinterpret_cast to convert the pointer to an integer type capable
 * of holding pointer values (`uintptr_t`). This is purely a bitwise
 * representation and not a deep serialization.
 */
uintptr_t	Serializer::serialize( Data *ptr ) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

/**
 * @brief Deserialize an integer back into a Data* pointer.
 *
 * Performs the inverse reinterpret_cast of `serialize()` to restore the
 * pointer value. The resulting pointer should only be used if the original
 * object still exists at the same address.
 */
Data * Serializer::deserialize( uintptr_t raw ) {
	return (reinterpret_cast<Data *>(raw));
}
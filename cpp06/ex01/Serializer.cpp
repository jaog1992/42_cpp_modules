/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:17:19 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/22 15:50:24 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new Serializer object with default values.
 */
Serializer::Serializer( void ) {
	std::cout << GREEN << "Serializer default constructor called" << RESET << std::endl;
}

/**
 * @brief  Default constructor for Serializer.
 * This class is intended to be non-instantiable by users; the constructor
 * is private to enforce static-only usage. The printed message is diagnostic.
 */

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
 * @brief  Copy constructor.
 * Copies the (unused) members from another Serializer instance.
 */

/**
 * @brief Destroy the Serializer object.
 */
Serializer::~Serializer( void ) {
	std::cout << RED << "Serializer destructor called" << RESET << std::endl;
}

/**
 * @brief  Destructor for Serializer.
 * Kept for symmetry but unnecessary for a static-only utility class.
 */
/* ------------ OVERLOAD METHODS ------------ */

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


uintptr_t	Serializer::serialize( Data *ptr ) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data * Serializer::deserialize( uintptr_t raw ) {
	return (reinterpret_cast<Data *>(raw));
}
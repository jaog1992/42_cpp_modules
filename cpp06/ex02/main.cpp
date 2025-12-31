/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:19:37 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/31 16:27:16 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <ctime>

/**
 * @brief Identifies the derived class type from a Base pointer.
 * 
 * This function checks if the provided Base pointer `p` points to an object of type A, B, 
 * or C.
 * 
 * @param p A pointer to the Base class or its derivatives.
 */
void	identify( Base *p ) {
	if (dynamic_cast<A *>(p)) {
		std::cout << 'A' << std::endl;
	} else if (dynamic_cast<B *>(p)) {
		std::cout << 'B' << std::endl;
	} else if (dynamic_cast<C *>(p)) {
		std::cout << 'C' << std::endl;
	} else {
		std::cout << "NULL" << std::endl;
	}
}

/**
 * @brief Identifies the derived class type from a Base reference.
 * 
 * This function operates similarly to the pointer-based version, but it uses references 
 * and C++'s `dynamic_cast` with `try-catch` blocks to handle the case where the cast fails. 
 * 
 * @param p A reference to the Base class or its derivatives.
 */
void	identify( Base &p ) {
	try {
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << 'A' << std::endl;
	} catch( const std::exception &ec ) {}
	try {
		B	&b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << 'B' << std::endl;
	} catch( const std::exception &ec ) {}
	try {
		C	&c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << 'C' << std::endl;
	} catch( const std::exception &ec ) {}
}

/**
 * @brief Randomly generate an instance of a derived class.
 *
 * This helper returns a freshly allocated object of type A, B or C chosen at
 * random. The caller is responsible for deleting the returned object.
 *
 * @return Base* Pointer to newly created object (A/B/C).
 */
Base* generate( void ) {
	switch (rand() % 3) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: return NULL;
	}
}

int	main( void ) {
	std::srand(std::time(NULL));
	Base *p = generate();

	identify(p);
	identify(*p);
	delete p;
	return 0;
}
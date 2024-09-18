/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:31:32 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 17:25:17 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
// #include <bitset>

// std::bitset<32> printBinary(int value)
// {
//     std::bitset<32> binary(value);
//     return(binary);
// }

// The fixed part of the fixed-point number is done using 24 bits.
// The fractional part of the fixed-point number is done using 8 bits(LSB).
// Each bit represents a fraction of a power of 2 as follows:
// Bit 0 (2^-1)  = 0.5
// Bit 1 (2^-2)  = 0.25
// Bit 2 (2^-3)  = 0.125
// Bit 3 (2^-4)  = 0.0625
// Bit 4 (2^-5)  = 0.03125
// Bit 5 (2^-6)  = 0.015625
// Bit 6 (2^-7)  = 0.0078125
// Bit 7 (2^-8)  = 0.00390625
// Therefore, the smallest fractional increment possible is 0.00390625, 
// and the value of the fractional part is a sum of these fractions.
int main(void) 
{
	Fixed 		a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// std::cout << "a is " << a <<
    // std::cout << "[aFloat, aBinaryFloat, aInt, aIntBinary]["
    //           << a << ", " 
    //           << printBinary(a.getRawBits()) << ", " 
    //           << a.toInt() << ", " 
    //           << printBinary(a.toInt()) << "]" << std::endl;

    // std::cout << "[bFloat, bBinaryFloat, bInt, bIntBinary]["
    //           << b << ", " 
    //           << printBinary(b.getRawBits()) << ", " 
    //           << b.toInt() << ", " 
    //           << printBinary(b.toInt()) << "]" << std::endl;

    // std::cout << "[cFloat, cBinaryFloat, cInt, cIntBinary]["
    //           << c << ", " 
    //           << printBinary(c.getRawBits()) << ", " 
    //           << c.toInt() << ", " 
    //           << printBinary(c.toInt()) << "]" << std::endl;

    // std::cout << "[dFloat, dBinaryFloat, dInt, dIntBinary]["
    //           << d << ", " 
    //           << printBinary(d.getRawBits()) << ", " 
    //           << d.toInt() << ", " 
    //           << printBinary(d.toInt()) << "]" << std::endl;
	return 0;
}
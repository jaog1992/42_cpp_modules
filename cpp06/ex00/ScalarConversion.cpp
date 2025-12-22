/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:17:52 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/22 15:51:14 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"
#include <cmath>
#include <cerrno>
#include <cctype>

/*
 * Default constructor. Initializes instance variables to 0.
 */
ScalarConversion::ScalarConversion( void ) {
	std::cout << GREEN << "ScalarConversion default constructor called" << RESET << std::endl;
}

/*

 * @brief Default constructor (diagnostic). The class is designed for static use
 * only; this private constructor should never be called by users.
 */

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
ScalarConversion::ScalarConversion( const ScalarConversion &oneScalarConversion ) {
	*this = oneScalarConversion;
	std::cout << GREEN << "ScalarConversion copy constructor called" << RESET << std::endl;
}

/*

 * @brief Copy constructor (diagnostic). Exists for completeness but not required
 * for a static-only utility class.
 */

/*
 * Overloading of the assignment operator.
 */
ScalarConversion & ScalarConversion::operator=( const ScalarConversion &oneScalarConversion ) {
	(void)oneScalarConversion;
	return *this;
}

/*

 * @brief Assignment operator overload. No-op implementation used so the class
 * remains non-instantiable in practice.
 */

/*
 * Destructor.
 */
ScalarConversion::~ScalarConversion( void ) {
	std::cout << RED << "ScalarConversion destructor called" << RESET << std::endl;
}

/*

 * @brief Destructor (diagnostic). Present only for parity with C++ object model.
 */

/*******************************CHAR CONVERSION*************************************/

void	ScalarConversion::charConversion( const char &c ) {
		if (isprint(c)) {
			std::cout << "char: '" << c << "'" << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}


/*******************************INT CONVERSION**************************************/

void	ScalarConversion::intConversion( const int &num ) {
	char	c = static_cast<char>(num);
	if (!isprint(c)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

bool	ScalarConversion::isInt( const std::string &literal ) {
	size_t	i = 0;

	if (literal[0] == '-' || literal[0] == '+') {
		i++;
	}
	while (i < literal.length()) {
		if (!isdigit(literal[i])) {
			return false;
		}
		i++;
	}
	double	num = atof(literal.c_str());
	if (num > INT_MAX || num < INT_MIN) {
		return false;
	}
	return true;
}


/*******************************FLOAT CONVERSION************************************/

bool	ScalarConversion::pseudoFloatConversion( const std::string &literal ) {
	if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
		return true;
	}
	return false;
}

bool	ScalarConversion::isFloat( const std::string &literal ) {
	(void)literal;
	return false; // replaced by robust parsing in convert()
}

void	ScalarConversion::floatConversion( const float &num ) {
	char	c = static_cast<char>(num);
	if (!isprint(c)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	if (num > INT_MAX|| num < INT_MIN) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	}
	if (std::floor(num) == num) {
		std::cout << "float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
	} else {
		std::cout << "float: " << num << "f" << std::endl;
	}
	double d = static_cast<double>(num);
	if (std::floor(d) == d) {
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	} else {
		std::cout << "double: " << d << std::endl;
	}
}

/******************************DOUBLE CONVERSION************************************/

bool	ScalarConversion::pseudoDoubleConversion( const std::string &literal ) {
	if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return true;
	}
	return false;
}

bool	ScalarConversion::isDouble( const std::string &literal ) {
	(void)literal;
	return false; // replaced by robust parsing in convert()
}

void	ScalarConversion::doubleConversion( const double &num ) {
	char	c = static_cast<char>(num);
	if (!isprint(c)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	if (num > INT_MAX|| num < INT_MIN) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	}
	float f = static_cast<float>(num);
	if (std::floor(f) == f) {
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	} else {
		std::cout << "float: " << f << "f" << std::endl;
	}
	if (std::floor(num) == num) {
		std::cout << "double: " << std::fixed << std::setprecision(1) << num << std::endl;
	} else {
		std::cout << "double: " << num << std::endl;
	}
}

/***********************************************************************************/



int ScalarConversion::convert( const std::string &literal ) {
	if (literal.length() == 1 && !isdigit(literal[0])) {
		charConversion(literal[0]);
		return 0;
	}

	if (pseudoFloatConversion(literal))
		return 0;
	if (pseudoDoubleConversion(literal))
		return 0;

	// Try int
	errno = 0;
	char *endptr = NULL;
	long int li = std::strtol(literal.c_str(), &endptr, 10);
	if (endptr && *endptr == '\0' && errno == 0 && li <= INT_MAX && li >= INT_MIN) {
		intConversion(static_cast<int>(li));
		return 0;
	}

	// Try float (ends with 'f')
	errno = 0;
	endptr = NULL;
	float fv = std::strtof(literal.c_str(), &endptr);
	if (endptr && *endptr == 'f' && *(endptr + 1) == '\0' && errno == 0) {
		floatConversion(fv);
		return 0;
	}

	// Try double
	errno = 0;
	endptr = NULL;
	double dv = std::strtod(literal.c_str(), &endptr);
	if (endptr && *endptr == '\0' && errno == 0) {
		doubleConversion(dv);
		return 0;
	}

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	return 0;
}

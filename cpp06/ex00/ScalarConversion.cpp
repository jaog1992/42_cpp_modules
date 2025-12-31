/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:17:52 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/31 04:41:36 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"
#include <cmath>
#include <cerrno>
#include <cctype>

/**
 * @brief Default constructor.
 *
 * This class is designed as a static utility; the default constructor
 * exists for parity but is not required for normal usage. It prints
 * a diagnostic message to standard output when invoked.
 */
ScalarConversion::ScalarConversion( void ) {
	std::cout << GREEN << "ScalarConversion default constructor called" << RESET << std::endl;
}

/*

 * @brief Default constructor (diagnostic). The class is designed for static use
 * only; this private constructor should never be called by users.
 */

/**
 * @brief Copy constructor.
 *
 * Performs a shallow copy of the provided instance. Present for completeness
 * but not required by the static usage pattern of the class.
 *
 * @param oneScalarConversion Reference to the ScalarConversion to copy.
 */
ScalarConversion::ScalarConversion( const ScalarConversion &oneScalarConversion ) {
	*this = oneScalarConversion;
	std::cout << GREEN << "ScalarConversion copy constructor called" << RESET << std::endl;
}

/*

 * @brief Copy constructor (diagnostic). Exists for completeness but not required
 * for a static-only utility class.
 */

/**
 * @brief Assignment operator.
 *
 * No-op assignment operator. Kept to fulfill the rule of three/five
 * but the class holds no mutable state that requires copying.
 *
 * @param oneScalarConversion Source object to assign from.
 * @return Reference to this instance.
 */
ScalarConversion & ScalarConversion::operator=( const ScalarConversion &oneScalarConversion ) {
	(void)oneScalarConversion;
	return *this;
}

/*

 * @brief Assignment operator overload. No-op implementation used so the class
 * remains non-instantiable in practice.
 */

/**
 * @brief Destructor.
 *
 * Prints a diagnostic message when the object is destroyed. The class
 * is effectively stateless and this destructor performs no special cleanup.
 */
ScalarConversion::~ScalarConversion( void ) {
	std::cout << RED << "ScalarConversion destructor called" << RESET << std::endl;
}

/*

 * @brief Destructor (diagnostic). Present only for parity with C++ object model.
 */

/*******************************CHAR CONVERSION*************************************/

/**
 * @brief Convert a single character literal to other scalar types and print results.
 *
 * Prints the `char` representation (or "Non displayable" if it is not printable),
 * the numeric `int` value, and the `float`/`double` representations. This function
 * follows the output style required by the exercise (adds ".0f" or ".0" when the
 * value is integral).
 *
 * @param c Character to convert.
 */
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

/**
 * @brief Convert an integer literal to other scalar types and print results.
 *
 * Attempts to cast the integer to `char` and prints whether it is displayable.
 * Also prints the `int` value itself and the `float`/`double` representations.
 * If the integer is outside the representable `char` range, the char output will
 * be shown as non-displayable according to the exercise rules.
 *
 * @param num Integer value to convert.
 */
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

/**
 * @brief Check whether a string represents a valid integer literal.
 *
 * This function verifies an optional sign followed by digits and ensures the
 * numeric value fits in the platform `int` range. It is used as a helper when
 * deciding which conversion path to take for a given input literal.
 *
 * @param literal String to test.
 * @return true if the string is a valid integer representation and fits in `int`.
 */


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

/**
 * @brief Check and print special float pseudo-literals.
 *
 * Handles float pseudo-literals such as `nanf`, `+inff`, `-inff`, and `inff`.
 * When matched, prints the canonical output lines expected by the exercise
 * and returns true to indicate the literal was handled.
 *
 * @param literal Input string to test.
 * @return true if the literal is a recognized pseudo-float.
 */

bool	ScalarConversion::isFloat( const std::string &literal ) {
	(void)literal;
	return false; // replaced by robust parsing in convert()
}

/**
 * @brief Heuristic: determine if a string could represent a float literal.
 *
 * This function is intentionally minimal because the `convert()` routine
 * performs robust parsing using `strtof`/`strtod`. The helper exists for
 * API completeness and potential future use.
 *
 * @param literal Input string to inspect.
 * @return true if the string resembles a float literal (not used currently).
 */


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

/**
 * @brief Convert a float value to other scalar types and print results.
 *
 * Prints the corresponding `char` (if printable), `int` (or `impossible` if
 * out of range), and `float`/`double` representations. Uses formatting to
 * append `.0` when the value is integral to match the expected output.
 *
 * @param num Float value to convert.
 */

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

/**
 * @brief Check and print special double pseudo-literals.
 *
 * Recognizes `nan`, `+inf`, `-inf`, and `inf` and prints the corresponding
 * outputs for char/int/float/double according to the exercise format.
 *
 * @param literal Input string to test.
 * @return true if the literal is a recognized pseudo-double.
 */

bool	ScalarConversion::isDouble( const std::string &literal ) {
	(void)literal;
	return false; // replaced by robust parsing in convert()
}

/**
 * @brief Heuristic: determine if a string could represent a double literal.
 *
 * As with `isFloat()`, the real parsing is done by `convert()`. This helper
 * exists for symmetry and potential future use.
 *
 * @param literal Input string to inspect.
 * @return true if the string resembles a double literal (not used currently).
 */

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

/**
 * @brief Convert a double value to other scalar types and print results.
 *
 * Behaves similarly to `floatConversion()` but starts from a `double`. It
 * prints the `char` (if displayable), `int` (or `impossible` when out of
 * range), the `float` representation (with trailing `f`) and the `double`
 * representation. Integral values are printed with a single decimal place.
 *
 * @param num Double value to convert.
 */

/***********************************************************************************/

int ScalarConversion::convert( const std::string &literal ) {
	if (literal.length() == 1 && !isdigit(literal[0])) {
		charConversion(literal[0]);
		return EXIT_SUCCESS;
	}

	if (pseudoFloatConversion(literal))
		return EXIT_SUCCESS;
	if (pseudoDoubleConversion(literal))
		return EXIT_SUCCESS;

	// Try int
	errno = 0;
	char *endptr = NULL;
	long int li = std::strtol(literal.c_str(), &endptr, 10);
	if (endptr && *endptr == '\0' && errno == 0 && li <= INT_MAX && li >= INT_MIN) {
		intConversion(static_cast<int>(li));
		return EXIT_SUCCESS;
	}

	// Try float (ends with 'f')
	errno = 0;
	endptr = NULL;
	float fv = std::strtof(literal.c_str(), &endptr);
	if (endptr && *endptr == 'f' && *(endptr + 1) == '\0' && errno == 0) {
		floatConversion(fv);
		return EXIT_SUCCESS;
	}

	// Try double
	errno = 0;
	endptr = NULL;
	double dv = std::strtod(literal.c_str(), &endptr);
	if (endptr && *endptr == '\0' && errno == 0) {
		doubleConversion(dv);
		return EXIT_SUCCESS;
	}

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	return EXIT_SUCCESS;
}

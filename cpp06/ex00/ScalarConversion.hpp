/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:17:56 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/31 11:52:04 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_H

# define SCALARCONVERSION_H

# include "../incs/Colors.hpp"
//# include <ctype.h>
# include <string>
# include <iostream>
# include <limits.h>
# include <cstdlib>
# include <iomanip>
class ScalarConversion {
	private:
		/**
		 * @brief Private default constructor to prevent instantiation.
		 */
		ScalarConversion(void);
		/**
		 * @brief Private copy constructor.
		 */
		ScalarConversion(const ScalarConversion &oneScalarConversion);
		/**
		 * @brief Private assignment operator.
		 */
		ScalarConversion &operator=(const ScalarConversion &oneScalarConversion);
		/**
		 * @brief Private destructor.
		 */
		~ScalarConversion(void);

		/**
		 * @brief Convert and print char results.
		 * This helper formats and prints conversions for a given character.
		 */
		static void	charConversion( const char &c );

		static bool	isInt( const std::string &literal );
		static void	intConversion( const int &num );
		static bool	isFloat( const std::string &literal );
		static void	floatConversion( const float &num );
		static bool isDouble( const std::string &literal );
		static void	doubleConversion( const double &num );
		static bool	pseudoDoubleConversion( const std::string &literal );
		static bool pseudoFloatConversion( const std::string &literal );

	public:
		static int	convert( const std::string &literal );
};

#endif
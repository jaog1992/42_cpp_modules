/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:17:56 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/31 15:38:04 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H

# define SCALARCONVERTER_H

# include "../incs/Colors.hpp"
# include <string>
# include <iostream>
# include <limits.h>
# include <cstdlib>
# include <iomanip>

class ScalarConverter {
	private:
		/**
		 * @brief Private default constructor to prevent instantiation.
		 */
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &oneScalarConversion);
		ScalarConverter &operator=(const ScalarConverter &oneScalarConversion);
		~ScalarConverter(void);

		static void	charConversion( const char &c );

		static bool	isInt( const std::string &literal );
		static void	intConversion( const int &num );

		static bool	isFloat( const std::string &literal );
		static void	floatConversion( const float &num );
		static bool pseudoFloatConversion( const std::string &literal );

		static bool isDouble( const std::string &literal );
		static void	doubleConversion( const double &num );
		static bool	pseudoDoubleConversion( const std::string &literal );

	public:
		static int	convert( const std::string &literal );
};

#endif
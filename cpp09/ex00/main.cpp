/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:08:45 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/31 17:48:53 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include "../incs/Colors.hpp"

/**
 * @brief Process an input file line-by-line and forward lines to the exchange.
 *
 * The file is expected to contain lines with the format `YYYY-MM-DD | value`.
 * Each non-empty line is passed to `BitcoinExchange::getNextCsvLine` and
 * any exceptions are reported to stderr.
 *
 * @param filename Path to the input file.
 * @param btc_exchange Reference to a prepared BitcoinExchange instance.
 */
void btc(const std::string& filename, BitcoinExchange& btc_exchange)
{
	std::ifstream input_file(filename.c_str());

	if (!input_file.is_open())
		throw std::runtime_error("Error opening file.");

	std::string line;

	std::getline(input_file, line);
	
	while (std::getline(input_file, line))
	{
		try
		{
			if (line.empty())
				continue;
			btc_exchange.getNextCsvLine(line);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	input_file.close();
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Invalid argument number - Usage: btc <filename>" << RESET << std::endl;
		return (EXIT_FAILURE);
	}

	try
	{
		BitcoinExchange btc_exchange; 

		btc_exchange.parseDatabaseCsv();
		btc(argv[1], btc_exchange);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return (EXIT_SUCCESS);
}


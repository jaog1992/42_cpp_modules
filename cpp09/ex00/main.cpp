/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:08:45 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/10 17:14:17 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <iostream>

void process_input_file(const std::string& filename, BitcoinExchange& btc_exchange)
{
	std::ifstream input_file(filename.c_str());
	if (!input_file.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::string line;
	std::getline(input_file, line);
	while (std::getline(input_file, line))
	{
		try
		{
			if (line.empty())
				continue;
			btc_exchange.processLine(line);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	input_file.close();
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid argument, please provide a file." << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange btc_exchange; 

		btc_exchange.parse_csv();
		process_input_file(argv[1], btc_exchange);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}


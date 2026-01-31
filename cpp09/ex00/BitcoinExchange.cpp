/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:08:26 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/31 18:09:07 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include "../incs/Colors.hpp"

BitcoinExchange::BitcoinExchange()
{
	//std::cout << GREEN << "BitcoinExchange default constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	//std::cout << GREEN << "BitcoinExchange copy constructor called" << RESET << std::endl;
	mapa = other.mapa;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	//std::cout << CYAN << "BitcoinExchange copy operator called" << RESET << std::endl;
	if (this != &other)
		mapa = other.mapa;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	//std::cout << RED << "BitcoinExchange destructor called" << RESET << std::endl;
}

std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r");

	if (std::string::npos == first)
	{
		return (str);
	}
	
	size_t last = str.find_last_not_of(" \t\n\r");
	
	return (str.substr(first, (last - first + 1)));
}

/**
 * @brief Check whether a date string appears valid (YYYY-MM-DD) with simple ranges.
 *
 * This performs syntactic checks and simple range checks for month and day.
 * It intentionally does not validate month-specific day counts (e.g., Feb 30).
 *
 * @param dataStr Date string to validate.
 * @return true if the date looks valid, false otherwise.
 */

void	BitcoinExchange::parseDatabaseCsv()
{
	std::ifstream file("data.csv");

	if (!file.is_open())
		throw std::runtime_error("Error: cannot open data.csv");

	std::string line;
    
	std::getline(file, line); // skip header
    
	while (std::getline(file, line))
	{
		size_t commaPosition = line.find(',');
		if (commaPosition == std::string::npos)
			throw std::out_of_range("Error: invalid values in data.csv");
		std::string dataStr = line.substr(0, commaPosition);
		std::string valueStr = line.substr(commaPosition + 1);

		float value;

		std::stringstream ss_value(valueStr);
        
		ss_value >> value;

		if (ss_value.fail() || !ss_value.eof())
			throw std::out_of_range("Error: invalid parameters in data.csv");
		mapa[dataStr] = value;
	}

	file.close();
}

bool	isValidDate(const std::string& dataStr)
{
	if (dataStr.length() != 10)
	{
		return (false);
	}
	if (dataStr[4] != '-' || dataStr[7] != '-')
	{
		return (false);
	}

	int year, month, day;
	char dash1, dash2;

	std::stringstream ss(dataStr);
	ss >> year >> dash1 >> month >> dash2 >> day;

	if (ss.fail() || dash1 != '-' || dash2 != '-')
		return (false);
	if ( month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	return (true);
}

bool	isValidValue(float value)
{
	if (value >= 0 && value <= 1000)
	{
		return (true);
	}
	return (false);
}

void	BitcoinExchange::getNextCsvLine(const std::string& line)
{
	size_t pipePosition = line.find('|');

	if (pipePosition == std::string::npos)
	{
		std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
		return ;
	}

	std::string dataStr = trim(line.substr(0, pipePosition));
	std::string valueStr = trim(line.substr(pipePosition + 1));

	if (!isValidDate(dataStr))
	{
		std::cerr << RED << "Error: bad input => " << dataStr << RESET << std::endl;
		return ;
	}

	float value;
	std::stringstream ss_value(valueStr);
	ss_value >> value;

	if (ss_value.fail() || !ss_value.eof())
	{
		throw std::runtime_error("Error: invalid number format.");
	}
	if (value < 0)
	{
		throw std::runtime_error("Error: not a positive number.");
	}
	if (value > 1000)
	{
		throw std::runtime_error("Error: too large a number.");
	}

	float rate = 0.0f;

	std::map<std::string, float>::iterator it = mapa.lower_bound(dataStr);
	if (it == mapa.end() || it->first != dataStr)
	{
		if (it == mapa.begin())
		{
			std::cerr << RED << "Error: no data available for date => " << dataStr << RESET << std::endl;
			return ;
		}
		--it;
	}

	rate = it->second;

	float result = value * rate;

	std::cout << dataStr << " => " << value << " = " << result << std::endl;
	
}


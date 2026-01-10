/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:08:26 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/10 17:14:23 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	std::cout << "Copy constructor called" << std::endl;
	mapa = other.mapa;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	std::cout << "Copy operator called" << std::endl;
	if (this != &other)
		mapa = other.mapa;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Destructor called" << std::endl;
}

std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (std::string::npos == first)
		return (str);
	size_t last = str.find_last_not_of(" \t\n\r");
	return (str.substr(first, (last - first + 1)));
}

void	BitcoinExchange::parse_csv()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("Error: cannot open data.csv");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t comma_pos = line.find(',');
		if (comma_pos == std::string::npos)
			throw std::out_of_range("Error: ivalid values");
		std::string data_str = line.substr(0, comma_pos);
		std::string value_str = line.substr(comma_pos + 1);

		float value;
		std::stringstream ss_value(value_str);
		ss_value >> value;

		if (ss_value.fail() || !ss_value.eof())
			throw std::out_of_range("Error: invalid parameters");
		mapa[data_str] = value;
	}
	file.close();
}

bool	isValidDate(const std::string& data_str)
{
	if (data_str.length() != 10)
		return (false);
	if (data_str[4] != '-' || data_str[7] != '-')
		return (false);

	int year, month, day;
	char dash1, dash2;
	std::stringstream ss(data_str);
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
		return (true);
	return (false);
}

void	BitcoinExchange::processLine(const std::string& line)
{
	size_t pipe_pos = line.find('|');
	if (pipe_pos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}

	std::string data_str = trim(line.substr(0, pipe_pos));
	std::string value_str = trim(line.substr(pipe_pos + 1));
	if (!isValidDate(data_str))
	{
		std::cerr << "Error: bad input => " << data_str << std::endl;
		return ;
	}

	float value;
	std::stringstream ss_value(value_str);
	ss_value >> value;

	if (ss_value.fail() || !ss_value.eof())
		throw std::runtime_error("Error: invalid number format.");
	if (value < 0)
		throw std::runtime_error("Error: not a positive number.");
	if (value > 1000)
		throw std::runtime_error("Error: too large a number.");
	float rate = 0.0f;

	std::map<std::string, float>::iterator it = mapa.lower_bound(data_str);
	if (it == mapa.end() || it->first != data_str)
	{
		if (it == mapa.begin())
		{
			std::cerr << "Error: no data available for date => " << data_str << std::endl;
			return ;
		}
		--it;
	}
	rate = it->second;
	float result = value * rate;

	std::cout << data_str << " => " << value << " = " << result << std::endl;
	
}


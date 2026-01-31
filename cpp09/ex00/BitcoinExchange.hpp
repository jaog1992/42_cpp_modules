/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:08:38 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/31 17:57:24 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <map>

class BitcoinExchange
{
	private:
		/**
		 * @brief Map that stores exchange rates keyed by date string (YYYY-MM-DD).
		 *
		 * Key: date as string (format "YYYY-MM-DD").
		 * Value: exchange rate for that date.
		 */
		std::map<std::string, float> mapa;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		/**
		 * @brief Load the exchange rates database from the bundled CSV file.
		 *
		 * This reads `data.csv` located next to the executable (or in the
		 * working directory) and populates the internal `mapa` with lines in
		 * the format `YYYY-MM-DD,rate`.
		 *
		 * @throws std::runtime_error if the file cannot be opened.
		 * @throws std::out_of_range if a line is malformed.
		 */
		void	parseDatabaseCsv();

		/**
		 * @brief Process a single input line from the user file.
		 *
		 * The input line is expected to have the format `YYYY-MM-DD | value`.
		 * This method validates the date and the value, looks up the nearest
		 * available rate (not after the date) and prints the computed result.
		 *
		 * @param line A single input line to process.
		 */
		void	getNextCsvLine(const std::string& line);

};

#endif

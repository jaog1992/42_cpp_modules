/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:45:15 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/23 21:45:15 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2):  _filename(filename), _search_string(s1), _replacement_string(s2) 
{
	std::ifstream input_file(filename.c_str());

	if (!input_file.is_open())
    {
		throw std::runtime_error(RED + "Error opening file." + RESET);
	}

	std::string new_filename = filename;
	std::string suffix = ".replace";

	_output_file.open(new_filename.append(suffix).c_str());
	if (!_output_file.is_open()) 
    {
		input_file.close();
		throw std::runtime_error(RED + "Error" + RESET + " creating output file.");
	}

	std::string line;

	while (std::getline(input_file, line)) 
    {
		_replace(line);
		if (!input_file.eof()) 
        {
			_output_file << std::endl;
		}
	}

	input_file.close();
	_output_file.close();
}

FileReplacer::~FileReplacer(void) 
{
	return ;
}

void FileReplacer::_replace(const std::string& line) 
{
	size_t	start_pos = 0;
	size_t	found_pos = line.find(_search_string, start_pos);

	while (found_pos != std::string::npos) 
    {
		_output_file << line.substr(start_pos, found_pos - start_pos) << _replacement_string;
		start_pos = found_pos + _search_string.length();
		found_pos = line.find(_search_string, start_pos);
	}
	_output_file << line.substr(start_pos, found_pos - start_pos);
}
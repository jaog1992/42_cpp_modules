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

/*
  c_str converts a std::string object into a null terminated char array (a c str)
  which is needed on the ifstream constructor and open fuction
  is_open returns a true if the file is open (file stream associated with the file)
*/
FileReplacer::FileReplacer(const std::string& filename, 
						   const std::string& s1,
						   const std::string& s2)
	:  _filename(filename),
	   _search_string(s1),
	   _replacement_string(s2) 
{
	std::ifstream input_file(filename.c_str());

	if (!input_file.is_open())
    {
		throw std::runtime_error(RED + "Error opening file." + RESET);
	}

	std::string suffix = ".replace";
	std::string new_filename = filename + suffix;

	_output_file.open(new_filename.c_str());

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

/* find searches for the first occurrence of the substring _search_string within the string line, 
   starting from the position start_pos. If found returns the first char index; else std::string::npos
   If the searched string is within the line we save it´s first char in found pos
   If found pos is not equal to std::string::npos then we write al the chars since
   start_pos to found pos to the output and then we add the replacement string.
   Then we move the start position to the end of this replace string in the output stream
   We then search for the next ocurrence of search_string for the next loop
   
   npos is the maximum value of size_t
*/
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
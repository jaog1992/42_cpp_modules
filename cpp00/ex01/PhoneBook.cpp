/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:37:24 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/17 15:37:24 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//Why are we using: _index(0)
PhoneBook::PhoneBook(void) : _index(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

// We reference the str value as const as we will not modify it´s values
// Not using & would imply making a copy of str and use more memory
bool isAllDigits(const std::string& str) {
    for (char c : str)
        if (!std::isdigit(static_cast<unsigned char>(c)))
            return false;
    return true;
}

// The use of do while is preferable to the use of while as this guarantees 
// the code being executed at least once.
std::string PhoneBook::_getBuffer(std::string msg, int mode) const
{
    std::string buff;
    
    do {
        std::cout << BLUE_ITALIC << msg << DEF_COLOR << std::flush;

        if (!std::getline(std::cin, buff)) {
            if (std::cin.eof()) {
                std::cout << std::endl;
                return EOF_CHECK;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << RED << "Error: Invalid input" << DEF_COLOR << std::endl;
            continue;
        }

        if (!buff.empty() && (mode == ALPHANUMERIC || (mode == NUMERIC && isAllDigits(buff))))
            return buff;
        else {
            std::cout << RED << "Error:" << DEF_COLOR << "  Invalid input" << std::endl;
        }

    } while (true);
}

std::string PhoneBook::_getInfo(void)
{
    this->_info[FIRSTNAME] = _getBuffer("  > Enter the first name: ", ALPHANUMERIC);
    if (this->_info[FIRSTNAME] == EOF_CHECK)
        return EOF_CHECK;
    this->_info[LASTNAME] = _getBuffer("  > Enter the last name: ", ALPHANUMERIC);
    if (this->_info[LASTNAME] == EOF_CHECK)
        return EOF_CHECK;
    this->_info[NICKNAME] = _getBuffer("  > Enter the nickname: ", ALPHANUMERIC);
    if (this->_info[NICKNAME] == EOF_CHECK)
        return EOF_CHECK;
    this->_info[PHONENUMBER] = _getBuffer("  > Enter the phone number: ", NUMERIC);
    if (this->_info[PHONENUMBER] == EOF_CHECK)
        return EOF_CHECK;
    this->_info[DARKESTSECRET] = _getBuffer("  > Enter the darkest secret: ", ALPHANUMERIC);
    if (this->_info[DARKESTSECRET] == EOF_CHECK)
        return EOF_CHECK;
    return "EXIT_SUCCESS";
}

void PhoneBook::addContact(void)
{
    if (_getInfo() == EOF_CHECK)
        exit(EXIT_SUCCESS);
    this->_contacts[this->_index % NUMBEROFCONTACTS].setInfo(this->_index % NUMBEROFCONTACTS, this->_info);
    this->_index++;
}

// std::setw: sets the minimum width of the input and adds spaces if less than n chars
// std:flush empties the buffer and shows the message instantly in the stdout
// (recommended when the user is interacting with the app)
// To left allign text (setw by default allings to right) use std::left
// To return to right allingment use std::right
void	PhoneBook::printContacts(void)
{
	std::cout << GREEN << "|" << std::setw(COLUMNWIDTH) << "INDEX" << std::flush;
	std::cout << "|" << std::setw(COLUMNWIDTH) << "FIRST NAME" << std::flush;
	std::cout << "|" << std::setw(COLUMNWIDTH) << "LAST NAME" << std::flush;
	std::cout << "|" << std::setw(COLUMNWIDTH) << "NICKNAME" << std::flush;
	std::cout << "|" << DEF_COLOR << std::endl;
	for (int i = 0; i < NUMBEROFCONTACTS; i++)
		this->_contacts[i].displayList();
}

// Users don´t know that arrays start at 0. 
// I am not a psicopath: User id-s start at 1. 
void	PhoneBook::display(void)
{
	std::string	buff;

	while (true)
	{
		std::cout << BLUE << "Input the index of the contact to display: " << DEF_COLOR;
		std::cin >> buff;
		if (buff.size() == 1 && buff[0] >= '1' && buff[0] <= '8')
		{
			this->_contacts[buff[0] - '1'].displayContact();
			break ;
		}
		else
			std::cout << RED << "Error:" << DEF_COLOR << " Enter a valid number" << std::endl;
	}
}
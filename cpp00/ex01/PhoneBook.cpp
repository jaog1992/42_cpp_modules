/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:37:24 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/19 13:55:20 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _index(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

bool isAllDigits(const std::string& str) 
{
    for (char c : str)
    {
        if (!std::isdigit(static_cast<unsigned char>(c)))
        {
            return false;
        }
    }

    return true;
}

std::string PhoneBook::_getBuffer(std::string msg, int mode) const
{
    std::string buff;
    
    do {
        std::cout << BLUE_ITALIC << msg << DEF_COLOR << std::flush;

        if (!std::getline(std::cin, buff))
        {
            if (std::cin.eof())
            {
                std::cout << std::endl;
                return EOF_CHECK;
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << RED << "Error: " << DEF_COLOR << "Invalid input"  << std::endl;
            continue;
        }

        if (!buff.empty() && (mode == ALPHANUMERIC || (mode == NUMERIC && isAllDigits(buff))))
        {
            return buff;
        }
        else
        {
            std::cout << RED << "    Error: " << DEF_COLOR << " Invalid input" << std::endl;
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
    {
        exit(EXIT_SUCCESS);
    }
    this->_contacts[this->_index % NUMBEROFCONTACTS].setInfo(this->_index % NUMBEROFCONTACTS, this->_info);
    this->_index++;
}

int	PhoneBook::printContacts(void)
{
	std::cout << GREEN << "|" << std::setw(COLUMNWIDTH) << "INDEX" << std::flush;
	std::cout << "|" << std::setw(COLUMNWIDTH) << "FIRST NAME" << std::flush;
	std::cout << "|" << std::setw(COLUMNWIDTH) << "LAST NAME" << std::flush;
	std::cout << "|" << std::setw(COLUMNWIDTH) << "NICKNAME" << std::flush;
	std::cout << "|" << DEF_COLOR << std::endl;
	
    for (int i = 0; i < NUMBEROFCONTACTS; i++)
    {
		if(this->_contacts[i].displayList() == LISTEMPTY_TRUE && i == 0)
        {
	        std::cout << std::endl;
            std::cout << YELLOW << "Warning: " << DEF_COLOR;
            std::cout << "The Phonebook is empty. Use the " << GREEN << "ADD" << DEF_COLOR << " command to enter the first contact" << std::endl;

            return LISTEMPTY_TRUE;
        }
    }

    return LISTEMPTY_FALSE;
}

void	PhoneBook::display(void)
{
	std::string	buff;

	while (true)
	{
		std::cout << BLUE_ITALIC << "> Input the index of the contact to display: " << DEF_COLOR;
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
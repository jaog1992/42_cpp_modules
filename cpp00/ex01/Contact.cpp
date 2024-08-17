/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:54:09 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/17 18:54:09 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

Contact::Contact(void) : _index(0)
{
}

Contact::~Contact(void)
{
}

void	Contact::setInfo(int index, std::string *info)
{
	this->_index = index;
	this->_FirstName = info[FIRSTNAME];
	this->_LastName = info[LASTNAME];
	this->_NickName = info[NICKNAME];
	this->_PhoneNumber = info[PHONENUMBER];
	this->_DarkestSecret = info[DARKESTSECRET];
}

std::string Contact::_truncateInfo(std::string info) const
{
    if (info.size() > COLUMNWIDTH)
        return info.substr(0, COLUMNWIDTH - 1) + ".";
    return info;
}

void	Contact::displayList(void)
{
	if (this->_FirstName.empty() || this->_LastName.empty() || this->_NickName.empty())
		return ;
	std::cout << "|" << std::setw(COLUMNWIDTH) << this->_index + 1;
	std::cout << "|" << std::setw(COLUMNWIDTH) << this->_truncateInfo(this->_FirstName);
	std::cout << "|" << std::setw(COLUMNWIDTH) << this->_truncateInfo(this->_LastName);
	std::cout << "|" << std::setw(COLUMNWIDTH) << this->_truncateInfo(this->_NickName);
	std::cout << "|" << std::endl;
}

void	Contact::displayContact(void)
{
	if (this->_FirstName.empty() || this->_LastName.empty() || this->_NickName.empty())
	{
		std::cout << RED << "Error:" << DEF_COLOR << " Empty contact" << std::endl;
		return ;
	}
	std::cout << GREEN << "  > First name:        " << DEF_COLOR << this->_FirstName<< std::endl;
	std::cout << GREEN << "  > Last name:         " << DEF_COLOR << this->_LastName<< std::endl;
	std::cout << GREEN << "  > Nickname:          " << DEF_COLOR << this->_NickName<< std::endl;
	std::cout << GREEN << "  > Phone number:      " << DEF_COLOR << this->_PhoneNumber<< std::endl;
	std::cout << GREEN << "  > Darkest secret:    " << DEF_COLOR << this->_DarkestSecret<< std::endl;
}

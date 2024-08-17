/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:32:09 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/17 15:32:09 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <limits>

// _getbuff() modes
# define ALPHANUMERIC     0
# define NUMERIC          1

// Fixed contact number
# define NUMBEROFCONTACTS 8

// Colors
# define RED              "\001\e[0;91m\002"
# define GREEN            "\001\e[0;92m\002"
# define BLUE             "\001\e[0;94m\002"
# define DEF_COLOR        "\001\e[0;39m\002"

// EOF check in contact addition
# define EOF_CHECK        "EOF_CHECK"

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void         addContact(void);
        void         printContacts(void);
        void         display(void);

    private:
		Contact		 _contacts[NUMBEROFCONTACTS];
		std::string	 _info[CONTACTINFO];
        int          _index;
        std::string  _getInfo(void);
        std::string  _getBuffer(std::string msg, int num) const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:12:51 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/17 16:12:51 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>

// _info array strings values
#define FIRSTNAME        0
#define LASTNAME         1
#define NICKNAME         2
#define PHONENUMBER      3
#define DARKESTSECRET    4
#define CONTACTINFO      5

// Fixed column width
#define COLUMNWIDTH      10

// Colors
# define RED              "\001\e[0;91m\002"
# define GREEN            "\001\e[0;92m\002"
# define BLUE             "\001\e[0;94m\002"
# define BLUE_ITALIC      "\001\e[3;94m\002"
# define DEF_COLOR        "\001\e[0;39m\002"

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        void        setInfo(int index, std::string *info);
        void        displayList(void);
        void        displayContact(void);

    private:
        int         _index;
        std::string _FirstName;
        std::string _LastName;
        std::string _NickName;
        std::string _PhoneNumber;
        std::string _DarkestSecret;
        std::string _truncateInfo(std::string info) const;
};

#endif
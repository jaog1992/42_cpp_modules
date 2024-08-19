/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:03:23 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/19 13:55:23 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int argc, char **argv)
{
	PhoneBook	book;
	std::string	buff;

	if (argc != 1)
		std::cout << RED << "Error: Invalid args" << DEF_COLOR << std::endl;
	else
	{
		while (true)
		{
			std::cout << BLUE << "Input a command: " << DEF_COLOR;
			std::cin >> buff;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.eof()) 
			{
				std::cout << std::endl;
			    break;
			}
			if (buff == "ADD")
				book.addContact();
			else if (buff == "SEARCH")
			{
				if(book.printContacts() == LISTEMPTY_FALSE)
				{
					book.display();
				}
			}
			else if (buff == "EXIT")
				break ;	
			else
			{
				std::cout << RED << "Error:" << DEF_COLOR << " Invalid command. The only valid commands are ";
				std::cout << GREEN << "ADD" << DEF_COLOR << ", ";
				std::cout << GREEN << "SEARCH" << DEF_COLOR << " and ";
				std::cout << GREEN << "EXIT" << DEF_COLOR << " (uppercase only)" << std::endl;
			}
		}
	}
	return (EXIT_SUCCESS);
}

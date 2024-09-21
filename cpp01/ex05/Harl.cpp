/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:43:40 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/22 20:43:40 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << RESET << std::endl << "**A Harl instance has been created**" << std::endl << RESET << std::endl;
}

Harl::~Harl(void)
{
	std::cout << RESET << "**Harl instance has been erased**" << std::endl << RESET << std::endl;
}

void	Harl::_debug(void)
{
	std::cout << BLUE << "DEBUG level comment. This correction is taking place in 42Urduliz." << RESET  << std::endl;
}

void	Harl::_info(void)
{
	std::cout << YELLOW << "INFO level comment. jde-orma is having a peer to peer evaluation of the cpp01 module on 42Urduliz" << RESET  << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << ORANGE << "WARNING level comment. This comments are different from Harl´s comments...but they prove jde-orma´s understanging about log levels. " << RESET  << std::endl;
}

void	Harl::_error(void)
{
	std::cout << RED << "ERROR level comment. jde-orma... ENOUGH ALREADY! THIS IS HARL! SHUTDOWN THE PROGRAM OR I AM MAKING A COMPLAIN TO THE STAFF!" << RESET << std::endl;
}

void	Harl::complain(const std::string& level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	// An array of pointers to member functions of the Harl class that return void and take no parameters
	void (Harl::*methods[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*methods[i])();
			return ;
		}
	}
	std::cout << WHITE << "That's ridiculous! Hey Varys! Did you know that jde-orma just bla bla bla bla... [in the distance]" << RESET << std::endl;
}

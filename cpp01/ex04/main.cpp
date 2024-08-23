/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:37:53 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/21 23:37:53 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int	main(int argc, char **argv)
{
	try 
    {
		if (argc != 4) 
        {
			throw std::runtime_error(RED + "Error: wrong number of arguments." + RESET);
		}
		FileReplacer(argv[1], argv[2], argv[3]);
		return (EXIT_SUCCESS);
	} catch (const std::exception& e) 
    {
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
}
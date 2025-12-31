/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:17:40 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/31 15:47:33 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int	main( int argc, char **argv ) {
	if (argc != 2) {
		std::cout << RED << "Argument count must be == 2 !" << RESET << std::endl;		
	} else {
		ScalarConverter::convert(argv[1]);		
	}

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:34:44 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/18 22:57:56 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::string metapod_name = "Metapod";
	std::string kakuna_name = "Kakuna";

	std::cout << std::endl << GREEN << "----- Constructor calls -----" << RESET << std::endl;
	ClapTrap metapod(metapod_name);
	ClapTrap kakuna(kakuna_name);

	std::cout << std::endl << GREEN << "----- Member function calls -----" << RESET << std::endl;

	std::cout << metapod.getName() << " uses strength" << std::endl;
	metapod.beRepaired(10);
	std::cout << kakuna.getName() << " goes berserk mode and uses tail attack (not very effective)." << std::endl;
	for (int i = 0; i < 11; i++)
		kakuna.attack(metapod.getName());
	std::cout << metapod.getName() << " won!" << std::endl;
	
	std::cout << std::endl << GREEN << "----- Destructor calls -----" << RESET << std::endl;

	return (0);	
}

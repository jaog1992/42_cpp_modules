/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:29:30 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/19 21:29:30 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << ">>Test 1: Instancing Basque Zombie Josepo" << std::endl;

	Zombie zombi1("Josepo");

	std::cout << zombi1.getName() << " will now announce himself -> ";

	zombi1.announce();

    std::cout << DEF_COLOR << std::endl;

	std::cout << ">>Test 2: Testing empty constructor." << std::endl;

	Zombie zombi2;

	std::cout << "Zombie with no name will announce himself -> ";

	zombi2.announce();

    std::cout << DEF_COLOR << std::endl;

	std::cout << ">>Test 3: Allocating Basque Zombie Maite (newZombie)" << std::endl;

	Zombie *zombi3;
	zombi3 = newZombie("Maite");

	std::cout << zombi3->getName() << " will now announce herself -> ";

	zombi3->announce();

	delete (zombi3);

	std::cout << std::endl;

	std::cout << ">>Test 4: Instancing Basque Zombie Perurena (randomChump())" << std::endl;

	randomChump("Perurena");

    std::cout << DEF_COLOR << std::endl;

	std::cout << ">>End of Zombie testing" << std::endl;
	
    std::cout << DEF_COLOR << std::endl;
	
    return (EXIT_SUCCESS);
}
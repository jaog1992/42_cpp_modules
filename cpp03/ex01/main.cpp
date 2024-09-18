/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:34:44 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/18 23:03:40 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

int	main(void)
{
	std::string scav_name = "Scavy";
	std::string scav_copy = "ScavyCopy";
	
	std::cout << std::endl << GREEN << "----- Constructor calls -----" << RESET << std::endl;
	ScavTrap scavy(scav_name);

	std::cout << std::endl << GREEN << "----- Inherited Member function calls -----" << RESET << std::endl;
	scavy.takeDamage(10);
	scavy.beRepaired(10);
	
	std::cout << std::endl << GREEN << "----- Modified Member function calls -----" << RESET << std::endl;
	scavy.attack("ENEMY1");
	scavy.guardGate();

	std::cout << std::endl << GREEN << "----- Operator overloads -----" << RESET << std::endl;
	ScavTrap scavy2 = scavy;
	scavy2.attack("ENEMY2");
	
	std::cout << std::endl << GREEN << "----- Copy constructor -----" << RESET << std::endl;
	ScavTrap scavy3(scavy2);
	scavy3.attack("ENEMY3");

	std::cout << std::endl << GREEN << "----- Polymorphism -----" << RESET << std::endl;
	ClapTrap *scavy4 = new ScavTrap(scav_copy);
	scavy4->attack("ENEMY4");
	/* scavy4->guardGate(); --> This woul cause a compilation error, as guardGate is not in the base clase! */
	ScavTrap *scavy5 = dynamic_cast<ScavTrap*>(scavy4);
	scavy5->setName("scavy5");
	scavy5->guardGate();
	
	std::cout << std::endl << GREEN << "----- Destructor calls -----" << RESET << std::endl;
	delete scavy4;
	delete scavy5;
	return (0);	
}

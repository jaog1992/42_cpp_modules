/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:04:42 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/18 23:22:26 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "Default FragTrap constructed!" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << getName() << " constructed!" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap " << getName() << " copy constructed!" << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << getName() << " destructed!" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	return (*this);
}

void		FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " says: \"High five, guys!\""
    << std::endl;
	return ;
}

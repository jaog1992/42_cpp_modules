/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:39:50 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/18 23:00:25 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "Default ScavTrap constructed!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string &name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << getName() << " constructed!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source)
{
	*this = source;
	std::cout << "ScavTrap " << getName() << " copy constructed!" << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << getName() << " destructed!" << std::endl;
	return ;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	return (*this);
}

void		ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << getName() << " attacks " << target
    << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	return ;
}

void		ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode." 
    << std::endl;
	return ;
}

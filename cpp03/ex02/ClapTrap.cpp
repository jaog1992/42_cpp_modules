/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:26:12 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/18 23:22:26 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) 
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap constructed!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string &name) 
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
	*this = source;
	std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " destructed!" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
		return (*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

int			ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

int			ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

int			ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}

void	ClapTrap::setName(std::string name)
{
	_name = name;
	return ;
}

void	ClapTrap::setHitPoints(int hitPoints)
{
	_hitPoints = hitPoints;
	return ;
}

void	ClapTrap::setEnergyPoints(int energyPoints)
{
	_energyPoints = energyPoints;
	return ;
}

void	ClapTrap::setAttackDamage(int attackDamage)
{
	_attackDamage = attackDamage;
	return ;
}

void	ClapTrap::attack(std::string const &target)
{
	if (!_hitPoints)
    {
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
		return ;
	} 
	if (!_energyPoints)
    {
		std::cout << "ClapTrap " << _name << " doesn't have enough energy to attack!" << std::endl;
		return ;
	} 
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "; 
	std::cout << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitPoints)
    {
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	if (amount >= static_cast<unsigned int>(_hitPoints))
    {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage and dies!" << std::endl;
	} else
    {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Remaining Hit Points: " << _hitPoints << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hitPoints)
    {
		std::cout << "ClapTrap " << _name << " is dead and cannot be repaired!" << std::endl;
		return ;
	} 
	if (!_energyPoints)
    {
		std::cout << "ClapTrap " << _name << " doesn't have enough energy to be repaired!" << std::endl;
		return ;
	} 
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points!" << std::endl;		
	_energyPoints -= 1;
	return ;
}

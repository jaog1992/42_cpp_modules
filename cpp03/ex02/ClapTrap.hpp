/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:26:27 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 18:26:27 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

class ClapTrap
{
    public:
	    ClapTrap(void);
	    ClapTrap(std::string &name);
	    ClapTrap(const ClapTrap &source);
	    virtual ~ClapTrap(void);

	    ClapTrap		&operator=(const ClapTrap &other);

	    std::string		getName(void) const;
	    int				getHitPoints(void) const;
	    int				getEnergyPoints(void) const;
	    int				getAttackDamage(void) const;

	    void			setName(std::string name);
	    void			setHitPoints(int hitPoints);
	    void			setEnergyPoints(int energyPoints);
	    void			setAttackDamage(int attackDamage);

	    virtual void	attack(std::string const &target);
	    void			takeDamage(unsigned int amount);
	    void			beRepaired(unsigned int amount);

    private:
	    std::string		_name;
	    int				_hitPoints;
	    int				_energyPoints;
	    int				_attackDamage;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:40:22 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/18 23:00:25 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
	    ScavTrap(void);
	    ScavTrap(std::string &name);
	    ScavTrap(const ScavTrap &source);
	    ~ScavTrap(void);

	    ScavTrap	&operator=(const ScavTrap &other);

	    void	attack(std::string const &target);
	    void	guardGate(void);
};

#endif
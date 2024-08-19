/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:20:18 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/19 21:20:18 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie(void)
{

}

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << GREEN << _name << BLUE << " has been summoned." << DEF_COLOR << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << BLUE << "Zombie " << GREEN << _name << BLUE << " now rests in peace" << DEF_COLOR << std::endl;

}

void Zombie::announce(void)
{
    std::cout << GREEN << _name << BLUE << ": BraiiiiiiinnnzzzZ..." << DEF_COLOR << std::endl;
}

void Zombie::setName(std::string name)
{
    _name = name;
}

std::string Zombie::getName(void)
{
    return _name;
}

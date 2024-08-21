/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:12:15 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/21 22:12:15 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon(void)
{
}

const std::string &Weapon::getType(void) const
{
    return this->_type;
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}

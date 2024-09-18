/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:28:01 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 19:28:01 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("") 
{
	std::cout << "Default abstract animal constructed!" << std::endl;
	return ;
}

AAnimal::AAnimal(std::string type) : _type(type) 
{
	std::cout << "Abstract animal of type " << _type << " constructed!"
	<< std::endl;
	return ;
}

AAnimal::AAnimal(const AAnimal& other) 
{
	*this = other;
	std::cout << "Abstract animal of type " << _type << " copy constructed!"
	<< std::endl;
	return ;
}

AAnimal::~AAnimal(void) 
{
	std::cout << "Abstract animal of type " << _type << " destructed!"
	<< std::endl;
	return ;
}

AAnimal	&AAnimal::operator=(const AAnimal& other) 
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

std::string	AAnimal::getType(void) const 
{
	return (_type);
}

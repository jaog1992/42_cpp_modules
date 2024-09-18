/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:14:47 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 19:14:47 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

Animal::Animal(void) : _type(""){
	std::cout << "Default animal constructed!" << std::endl;
	return ;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal " << _type << " constructed!" << std::endl;
	return ;
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "Animal " << _type << " copy constructed!" << std::endl;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Animal " << _type << " destructed!" << std::endl;
	return ;
}

Animal	&Animal::operator=(const Animal& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal ";
	if (_type != "")
		std::cout << _type << " ";
	std::cout << "says: \"...\"" << std::endl;
	return ;
}

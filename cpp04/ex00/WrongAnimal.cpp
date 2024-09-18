/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:19:19 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 19:19:19 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("")
{
	std::cout << "WrongAnimal default constructor called!" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal " << _type << " constructor called!"
    << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	*this = other;
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called!" << std::endl;
	return ;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

void		WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal " << _type << " says: \"...\"" << std::endl;
	return ;
}
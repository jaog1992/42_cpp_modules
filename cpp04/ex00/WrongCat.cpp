/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:21:21 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 19:21:21 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called!" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongCat copy constructor called!" << std::endl;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called!" << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:18:08 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 19:18:08 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
	std::cout << "Dog constructed!" << std::endl;
	return ;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	*this = other;
	std::cout << "Dog copy constructed!" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructed!" << std::endl;
	return ;
}

Dog	&Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog says: \"Woof!\"" << std::endl;
	return ;
}

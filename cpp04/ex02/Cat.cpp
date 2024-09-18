/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:16:56 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 19:16:56 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
	std::cout << "Cat constructed!" << std::endl;
	return ;
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	*this = other;
	std::cout << "Cat copy constructed!" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructed!" << std::endl;
	return ;
}

Cat	&Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat says: \"Meow!\"" << std::endl;
	return ;
}

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
	this->_brain = new Brain();
	std::cout << "Cat constructed!" << std::endl;
	return ;
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructed!" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat destructed!" << std::endl;
	return ;
}

Cat	&Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	AAnimal::operator=(other);
	if (this->_brain != NULL)
		delete this->_brain;
	this->_brain = new Brain(*other._brain);
	std::cout << "Cat assignment operator called!" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat says: \"Meow!\"" << std::endl;
	return ;
}

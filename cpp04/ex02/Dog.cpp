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
	this->_brain = new Brain();
	std::cout << "Dog constructed!" << std::endl;
	return ;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructed!" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog destructed!" << std::endl;
	return ;
}

Dog	&Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	AAnimal::operator=(other);
	if (this->_brain != NULL)
		delete this->_brain;
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog assignment operator called!" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog says: \"Woof!\"" << std::endl;
	return ;
}

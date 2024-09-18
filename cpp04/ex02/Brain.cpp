/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:24:42 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 19:24:42 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

Brain::Brain(void)
{
	std::stringstream ss;
	for (int i = 0; i < 100; i++)
	{
		ss << i;
		_ideas[i] = "Idea #" + ss.str();
	}
	std::cout << "Brain constructed!" << std::endl;
	return ;
}

Brain::Brain(const Brain &source)
{
	*this = source;
	std::cout << "Brain copy constructed!" << std::endl;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructed!" << std::endl;
	return ;
}

Brain	&Brain::operator=(const Brain &other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	return (*this);
}

std::string	*Brain::getIdeas(void)
{
	return (_ideas);
}
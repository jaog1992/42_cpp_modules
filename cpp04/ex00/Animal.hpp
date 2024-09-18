/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:15:25 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/18 23:46:53 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{

    public:
    	Animal(void);
    	Animal(std::string animal_type);
    	Animal(const Animal& other);
    	virtual ~Animal(void);

    	Animal	&operator=(const Animal& other);

    	std::string		getType(void) const;
    	virtual void	makeSound(void) const;

    protected:
    	std::string _type;

};

#endif
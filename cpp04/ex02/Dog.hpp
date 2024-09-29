/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:18:42 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 19:18:42 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    public:
    	Dog(void);
    	Dog(const Dog& other);
    	virtual ~Dog(void);

    	Dog	&operator=(const Dog& other);

    	virtual void	makeSound(void) const;
	
	private:
		Brain 		*_brain;
};

#endif
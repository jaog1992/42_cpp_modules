/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:17:31 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 19:17:31 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal
{
    public:
    	Cat(void);
    	Cat(const Cat& other);
    	virtual ~Cat(void);
    
    	Cat	&operator=(const Cat& other);
    
    	virtual void	makeSound(void) const;
};

#endif
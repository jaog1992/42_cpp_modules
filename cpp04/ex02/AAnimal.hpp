/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:28:12 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/19 00:10:24 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class AAnimal
{
    public:
	    std::string getType(void) const;
	    virtual void makeSound(void) const = 0; // Pure virtual function

    protected:
    	std::string _type;
    	AAnimal(void);
    	AAnimal(std::string type);
    	AAnimal(const AAnimal& other);

    	virtual ~AAnimal(void);

    	AAnimal& operator=(const AAnimal& other);
};

#endif
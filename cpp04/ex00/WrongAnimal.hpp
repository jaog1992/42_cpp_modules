/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:20:24 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 19:20:24 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{

    public:
    	WrongAnimal(void);
    	WrongAnimal(std::string wrongAnimal_type);
    	WrongAnimal(const WrongAnimal& other);
    	virtual ~WrongAnimal(void);

    	WrongAnimal	&operator=(const WrongAnimal &other);

    	std::string	getType(void) const;
    	void		makeSound(void) const;

    protected:
    	std::string _type;
};

#endif
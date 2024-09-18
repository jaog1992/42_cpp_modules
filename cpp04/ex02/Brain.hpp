/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:25:18 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 19:25:18 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class Brain
{

    public:
    	Brain(void);
    	Brain(const Brain &source);
    	~Brain(void);

    	Brain	&operator=(const Brain &other);

    	std::string	*getIdeas(void);
    
    private:
    	std::string _ideas[100];
};

#endif
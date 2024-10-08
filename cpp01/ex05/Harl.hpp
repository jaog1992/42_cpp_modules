/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:42:41 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/22 20:42:41 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <cstdlib>

// Colors
const std::string RESET = "\033[0m";
const std::string RED = "\033[1;31m";
const std::string YELLOW = "\033[1;33m";
const std::string BLUE = "\033[1;34m";
const std::string WHITE = "\033[1;37m";
const std::string ORANGE = "\033[1;38;5;202m";

class Harl
{
    public:
	    Harl(void);
	    ~Harl(void);
	    void	complain(const std::string& level);

    private:
    	void	_debug(void);
    	void	_info(void);
    	void	_warning(void);
    	void	_error(void);
};

#endif
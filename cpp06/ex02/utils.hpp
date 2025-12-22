/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:20:17 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/22 15:20:19 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP

# define UTILS_HPP

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include "Base.hpp"
# include <stdlib.h>
# include <ctime>

Base * generate( void );
void	identify( Base &p );
void	identify( Base *p );

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:19:17 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/31 11:52:08 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP

# define BASE_HPP

# include "../incs/Colors.hpp"
# include <iostream>

/**
 * @brief Abstract base class used for RTTI exercises.
 *
 * Declares a virtual destructor to allow proper cleanup from derived
 * pointers and to enable runtime type identification via dynamic_cast.
 */
class Base {
	public:
		virtual ~Base( void );
};

#endif
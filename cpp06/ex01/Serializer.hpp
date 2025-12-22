/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:18:39 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/22 15:18:42 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP

# define SERIALIZER_HPP

# include "../incs/Colors.hpp"
# include "Data.h"
# include <string>
# include <iostream>
# include <stdint.h>

class Serializer {
	private:
		Serializer( void );
		Serializer( const Serializer &otherSerialize );
		Serializer & operator=( const Serializer &otherSerialize );
		~Serializer( void );

	public:
		static uintptr_t serialize( Data* ptr );
		static Data* deserialize( uintptr_t raw );
};

#endif
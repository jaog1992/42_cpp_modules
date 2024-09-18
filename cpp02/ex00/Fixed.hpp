/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:57:46 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/15 22:57:46 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cstdlib>

class Fixed
{
    public:
        Fixed(void);
        /* Copy contructor */
        Fixed(const Fixed &other);        
        ~Fixed(void);
        /* = operator overload */
        Fixed &operator=(const Fixed &other);
        int   getRawBits(void) const;
        void  setRawBits(int const raw); 

    private:
        int _fixed;
        static const int _fractionalBits = 8;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:57:46 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 17:56:40 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cstdlib>
#include <cmath>

class Fixed
{
    public:
        Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        ~Fixed(void);

        Fixed   &operator=(const Fixed &other);
	    bool	operator>(const Fixed &other) const;
	    bool	operator<(const Fixed &other) const;
	    bool	operator>=(const Fixed &other) const;
	    bool	operator<=(const Fixed &other) const;
	    bool	operator==(const Fixed &other) const;
	    bool	operator!=(const Fixed &other) const;
	    Fixed	operator+(const Fixed &other) const;
	    Fixed	operator-(const Fixed &other) const;
	    Fixed	operator*(const Fixed &other) const;
	    Fixed	operator/(const Fixed &other) const;
	    Fixed	&operator++(void);
	    Fixed	operator++(int);
	    Fixed	&operator--(void);
	    Fixed	operator--(int);

        int   getFixed(void) const;
        void  setFixed(int const raw);
        float toFloat(void) const;
        int   toInt(void) const;

	    static Fixed	&min(Fixed &a, Fixed &b);
	    static const Fixed	&min(const Fixed &a, const Fixed &b);
	    static Fixed	&max(Fixed &a, Fixed &b);
	    static const Fixed	&max(const Fixed &a, const Fixed &b);

    private:
        int _fixed;
        static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
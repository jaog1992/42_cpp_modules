/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:07:52 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 17:25:17 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed &other) : _fixed(other._fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _fixed = value << _fractionalBits;
    return ;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _fixed = roundf(value * (1 << _fractionalBits));
    return ;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

/* We protect autoassignment*/
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    _fixed = other.getFixed();
    return (*this);
}

int Fixed::getFixed(void) const
{
    return(_fixed);
}

void Fixed::setFixed(int const fixed)
{
    _fixed = fixed;
    return ;
}

float Fixed::toFloat(void) const
{
    return((float)_fixed / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (_fixed >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}


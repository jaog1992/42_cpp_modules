/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:07:52 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 17:56:40 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed &other) : _fixed(other.getRawBits())
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

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    _fixed = other.getRawBits();
    return (*this);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (_fixed > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_fixed < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_fixed >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_fixed <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_fixed == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_fixed != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	_fixed++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	_fixed--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

int Fixed::getRawBits(void) const
{
    return(_fixed);
}

void Fixed::setRawBits(int const fixed)
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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}


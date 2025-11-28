/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:11:30 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 15:11:34 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const int value)
{
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	_value = other._value;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_value = other._value;
	return (*this);
}

float Fixed::toFloat() const
{
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
	return (_value >> _fractionalBits);
}

Fixed &Fixed::operator++() // prefix
{
	_value += 1;
	return (*this);
}

Fixed Fixed::operator++(int) // postfix
{
	Fixed temp(*this);
	_value += 1;
	return (temp);
}

Fixed Fixed::operator*(Fixed const &other) const
{
	Fixed result;
	long tmp = (long)_value * (long)other._value;
	result._value = tmp >> _fractionalBits;
	return (result);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._value >= b._value)
		return (a);
	else
		return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

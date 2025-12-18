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

Fixed &Fixed::operator++()
{
	++_value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	_value++;
	return (temp);
}

Fixed Fixed::operator--()
{
	--_value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	_value--;
	return (temp);
}

Fixed Fixed::operator+(Fixed const &other) const
{
	Fixed result;

	result._value = _value + other._value;
	return (result);
}

Fixed Fixed::operator-(Fixed const &other) const
{
	Fixed result;

	result._value = _value - other._value;
	return (result);
}

Fixed Fixed::operator*(Fixed const &other) const
{
	Fixed result;
	long tmp;

	tmp = (long)_value * (long)other._value;
	result._value = tmp >> _fractionalBits;
	return (result);
}

Fixed Fixed::operator/(Fixed const &other) const
{
	Fixed result;
	long tmp;

	tmp = ((long)_value << _fractionalBits) / (long)other._value;
	result._value = tmp;
	return (result);
}

Fixed Fixed::operator!=(Fixed const &other) const
{
	return (_value != other._value);
}

Fixed Fixed::operator==(Fixed const &other) const
{
	return (_value == other._value);
}

Fixed Fixed::operator>=(Fixed const &other) const
{
	return (_value >= other._value);
}

Fixed Fixed::operator<=(Fixed const &other) const
{
	return (_value <= other._value);
}

Fixed Fixed::operator>(Fixed const &other) const
{
	return (_value > other._value);
}

Fixed Fixed::operator<(Fixed const &other) const
{
	return (_value < other._value);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._value >= b._value)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a._value >= b._value)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._value <= b._value)
		return (a);
	else
		return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a._value <= b._value)
		return (a);
	else
		return (b);
}

int Fixed::getRawBits() const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

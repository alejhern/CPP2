/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:10:01 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 15:10:06 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int					_value;
	static const int	_fractionalBits = 8;

  public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	~Fixed();
	float toFloat() const;
	int toInt() const;
	Fixed &operator=(const Fixed &other);
	Fixed &operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);
	Fixed operator+(Fixed const &other) const;
	Fixed operator-(Fixed const &other) const;
	Fixed operator*(Fixed const &other) const;
	Fixed operator/(Fixed const &other) const;
	Fixed operator!=(Fixed const &other) const;
	Fixed operator==(Fixed const &other) const;
	Fixed operator>=(Fixed const &other) const;
	Fixed operator<=(Fixed const &other) const;
	Fixed operator>(Fixed const &other) const;
	Fixed operator<(Fixed const &other) const;
	static const Fixed &max(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);
	int getRawBits() const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

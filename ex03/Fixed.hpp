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

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int _value;
	static const int _fractionalBits = 8;

  public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	~Fixed();

	Fixed &operator=(const Fixed &other);

	float toFloat() const;
	int toInt() const;

	Fixed &operator++();   // prefix
	Fixed operator++(int); // postfix

	Fixed operator*(Fixed const &other) const;

	static const Fixed &max(const Fixed &a, const Fixed &b);

	int getRawBits() const
	{
		return (_value);
	}
	void setRawBits(int const raw)
	{
		_value = raw;
	}
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

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

# include <iostream>

class Fixed
{
private:
	float 				_value;
	static const int	_frac_bits = 8;
public:
	Fixed(void);
	Fixed(const int intValue);
	Fixed(const float floatValue);
	Fixed(const Fixed &other);
	~Fixed();
	Fixed &operator=(const Fixed &other);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
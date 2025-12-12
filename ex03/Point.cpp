/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 23:20:08 by alejhern          #+#    #+#             */
/*   Updated: 2025/12/12 23:20:12 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
    {
        // _x and _y are const, so we cannot assign to them
        // This operator= is effectively useless in this case
    }
    return (*this);
}

Fixed Point::getX() const
{
    return (_x);
}

Fixed Point::getY() const
{
    return (_y);
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
    out << "(" << point.getX().toFloat() << ", " << point.getY().toFloat() << ")";
    return (out);
}

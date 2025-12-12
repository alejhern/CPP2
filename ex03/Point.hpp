/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 23:05:59 by alejhern          #+#    #+#             */
/*   Updated: 2025/12/12 23:06:03 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
class Point
{
private:
    Fixed const _x;
    Fixed const _y;
public:
    Point();
    Point(const float x, const float y);
    Point(const Point &other);
    ~Point();
    Point &operator=(const Point &other);
    Fixed getX() const;
    Fixed getY() const;
};
std::ostream &operator<<(std::ostream &out, const Point &point);
bool bsp(const Point &a, const Point &b, const Point &c, const Point &point);
#endif
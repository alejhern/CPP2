/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 23:11:26 by alejhern          #+#    #+#             */
/*   Updated: 2025/12/22 15:55:21 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	area(const Point &a, const Point &b, const Point &c)
{
	float	area;

	area = ((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()))
			+ (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()))
			+ (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())))
		/ 2;
	if (area < 0)
		area *= -1;
	return (area)
}

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &point)
{
	const float	EPS = 1e-6f;
	float		d0;
	float		d1;
	float		d2;
	float		d3;

	d0 = area(a, b, c);
	if (d0 < EPS)
		return (false);
	d1 = area(point, b, c);
	d2 = area(a, point, c);
	d3 = area(a, b, point);
	if (!d1 || !d2 || !d3)
		return (false);
	return (d0 == d1 + d2 + d3);
}

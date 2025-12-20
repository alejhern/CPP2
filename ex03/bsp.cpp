/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 23:11:26 by alejhern          #+#    #+#             */
/*   Updated: 2025/12/20 22:36:06 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	area(const Point &a, const Point &b, const Point &c)
{
	float	ax;
	float	ay;
	float	bx;
	float	by;
	float	cx;
	float	cy;

	ax = a.getX().toFloat();
	ay = a.getY().toFloat();
	bx = b.getX().toFloat();
	by = b.getY().toFloat();
	cx = c.getX().toFloat();
	cy = c.getY().toFloat();
	return (fabs((ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) / 2.0f));
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
	return (fabs(d0 - (d1 + d2 + d3)) < EPS && d1 > EPS && d2 > EPS
		&& d3 > EPS);
}

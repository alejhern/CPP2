/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:42:13 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 15:42:19 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(0.0f, 5.0f);

	Point insidePoint(1.0f, 1.0f);
	Point outsidePoint(6.0f, 6.0f);
	Point edgePoint(0.0f, 2.5f);

	std::cout << "Triangle vertices: " << a << ", " << b << ", " << c << std::endl;
	std::cout << "Testing point " << insidePoint << ": "
			  << (bsp(a, b, c, insidePoint) ? "Inside" : "Outside") << std::endl;
	std::cout << "Testing point " << outsidePoint << ": "
			  << (bsp(a, b, c, outsidePoint) ? "Inside" : "Outside") << std::endl;
	std::cout << "Testing point " << edgePoint << ": "
			  << (bsp(a, b, c, edgePoint) ? "Inside" : "Outside") << std::endl;	
	return (0);
}

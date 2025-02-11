/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:55:06 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/05 12:25:41 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include "./Point.hpp"

// code from https://stackoverflow.com/a/2049593

// this basically calculate the derterminent to know which side the of the line p1->p2 is
Fixed cross_product(Point point, Point p1, Point p3)
{
	return (point.getX() - p3.getX()) * (p1.getY() - p3.getY()) - (p1.getX() - p3.getX()) * (point.getY() - p3.getY());
}
// this checks that the triangle is only either on side A (negative) or on side B (positive) of each line that comprise
// the triangle if the point is outside said triangle, then the point is on side A for some lines AND side B for other
// line
// https://math.stackexchange.com/questions/51326/determining-if-an-arbitrary-point-lies-inside-a-triangle-defined-by-three-points
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = cross_product(point, a, b);
	Fixed d2 = cross_product(point, b, c);
	Fixed d3 = cross_product(point, c, a);



	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}


// code from https://stackoverflow.com/a/2049593

// this basically calculate the derterminent to know which side the of the line p1->p2 is
double cross_product(PointDouble point, PointDouble p1, PointDouble p3)
{
	return (point.getX() - p3.getX()) * (p1.getY() - p3.getY()) - (p1.getX() - p3.getX()) * (point.getY() - p3.getY());
}
// this checks that the triangle is only either on side A (negative) or on side B (positive) of each line that comprise
// the triangle if the point is outside said triangle, then the point is on side A for some lines AND side B for other
// line
// https://math.stackexchange.com/questions/51326/determining-if-an-arbitrary-point-lies-inside-a-triangle-defined-by-three-points
bool bsp(PointDouble const a, PointDouble const b, PointDouble const c, PointDouble const point)
{
	double d1 = cross_product(point, a, b);
	double d2 = cross_product(point, b, c);
	double d3 = cross_product(point, c, a);



	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}

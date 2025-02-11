/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:48:26 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/09 14:46:36 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include "./Point.hpp"

#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);
bool bsp(PointDouble const a, PointDouble const b, PointDouble const c,
		 PointDouble const point);

void check(Point top, Point left, Point right, Point point)
{
	std::cout << "(" << point.getX() << ", " << point.getY() << ")";
	if (bsp(top, left, right, point))
		std::cout << " is inside the triangle" << std::endl;
	else
		std::cout << " is outside the triangle" << std::endl;
}

void check(PointDouble top, PointDouble left, PointDouble right,
		   PointDouble point)
{
	std::cout << "(" << point.getX() << ", " << point.getY() << ")";
	if (bsp(top, left, right, point))
		std::cout << " is inside the triangle" << std::endl;
	else
		std::cout << " is outside the triangle" << std::endl;
}

int main(void)
{
	Point top = Point(0, 1);
	Point left = Point(-1, -1);
	Point right = Point(1, -1);

	Point inside = Point(0, 0);
	Point close = Point(0, 1.01f);
	Point outside = Point(2, 1);
	Point edge = Point(0, -1);

	check(top, left, right, inside);
	check(top, left, right, outside);
	check(top, left, right, top);
	check(top, left, right, close);
	check(top, left, right, edge);

	std::cout << "\nSame algo with double for precision :" << std::endl;
	PointDouble top_ = PointDouble(0, 1);
	PointDouble left_ = PointDouble(-1, -1);
	PointDouble right_ = PointDouble(1, -1);

	PointDouble inside_ = PointDouble(0, 0);
	PointDouble close_ = PointDouble(0, 1.01f);
	PointDouble outside_ = PointDouble(2, 1);
	PointDouble edge_ = PointDouble(0, -1);

	check(top_, left_, right_, inside_);
	check(top_, left_, right_, outside_);
	check(top_, left_, right_, top_);
	check(top_, left_, right_, close_);
	check(top_, left_, right_, edge_);

	return 0;
}

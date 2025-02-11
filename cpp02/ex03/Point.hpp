/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:39:33 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/09 14:42:09 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "./Fixed.hpp"

/// This defines the needed function for the Orthodox canonical form
#define declare_OCF(ClassName)                                                 \
	ClassName();                                                               \
	~ClassName();                                                              \
	ClassName(const ClassName &);                                              \
	ClassName &operator=(ClassName &);

class Point
{
  public:
	declare_OCF(Point);

	Point(float x, float y);
	Point(int x, int y);
	Point(float x, int y);
	Point(int x, float y);

	Fixed getX() const;
	Fixed getY() const;

  private:
	// letsgo c'est pas possible le const pour le assigment operator
	Fixed x;
	Fixed y;
};

class PointDouble
{
  public:
	declare_OCF(PointDouble);

	PointDouble(float x, float y);
	PointDouble(int x, int y);
	PointDouble(float x, int y);
	PointDouble(int x, float y);

	double getX() const;
	double getY() const;

  private:
	// letsgo c'est pas possible le const pour le assigment operator
	double x;
	double y;
};

#endif /* POINT_HPP */

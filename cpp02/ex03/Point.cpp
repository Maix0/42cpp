/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:49:15 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/05 12:28:48 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"
#include "./Fixed.hpp"

Point::Point() : x(0), y(0) {};
Point::Point(const Point &other) : x(other.x), y(other.y) {};
Point::Point(int x, int y) : x(x), y(y) {};
Point::Point(float x, float y) : x(x), y(y) {};
Point::Point(float x, int y) : x(x), y(y) {};
Point::Point(int x, float y) : x(x), y(y) {};

Point::~Point() {};

Point &Point::operator=(Point &other) {
  this->x = other.x;
  this->y = other.y;
  return (*this);
}

Fixed Point::getX() const { return (this->x); }

Fixed Point::getY() const { return (this->y); }

PointDouble::PointDouble() : x(0), y(0) {};
PointDouble::PointDouble(const PointDouble &other) : x(other.x), y(other.y) {};
PointDouble::PointDouble(int x, int y) : x(x), y(y) {};
PointDouble::PointDouble(float x, float y) : x(x), y(y) {};
PointDouble::PointDouble(float x, int y) : x(x), y(y) {};
PointDouble::PointDouble(int x, float y) : x(x), y(y) {};

PointDouble::~PointDouble() {};

PointDouble &PointDouble::operator=(PointDouble &other) {
  this->x = other.x;
  this->y = other.y;
  return (*this);
}

double PointDouble::getX() const { return (this->x); }

double PointDouble::getY() const { return (this->y); }

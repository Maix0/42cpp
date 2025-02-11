/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:48:34 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/05 12:48:22 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <bitset>
#include <cmath>
#include <iostream>

const int Fixed::fractionBitsWidth = 8;

Fixed::~Fixed() {};

Fixed::Fixed()
{
	this->bits = 0;
}

Fixed::Fixed(int val)
{
	this->bits = val * (1 << (Fixed::fractionBitsWidth));
}

Fixed::Fixed(float val)
{
	this->bits = val * (1 << (Fixed::fractionBitsWidth));
}

float Fixed::toFloat(void) const
{
	return ((float)this->bits / (float)(1 << (Fixed::fractionBitsWidth)));
}

int Fixed::toInt(void) const
{
	return ((int)this->bits / (int)(1 << (Fixed::fractionBitsWidth)));
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	this->bits = rhs.bits;

	return (*this);
}

Fixed::Fixed(const Fixed& rhs)
{
	this->bits = rhs.bits;
}

int Fixed::getRawBits() const
{
	return (this->bits);
}

void Fixed::setRawBits(const int raw)
{
	this->bits = raw;
}

std::ostream& operator<<(std::ostream& o, const Fixed& rhs)
{
	o << rhs.toFloat();
	return (o);
}

enum Ordering Fixed::cmp(const Fixed& rhs) const
{
	if (this->bits == rhs.bits)
		return (EQ);
	if (this->toFloat() > rhs.toFloat())
		return (GT);
	return (LT);
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
	if (lhs < rhs)
		return (rhs);
	return (lhs);
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs < rhs)
		return (rhs);
	return (lhs);
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs)
{
	if (lhs > rhs)
		return (rhs);
	return (lhs);
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs > rhs)
		return (rhs);
	return (lhs);
}

Fixed& Fixed::operator++()
{
	this->bits++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->bits--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	this->bits++;
	return (old);
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	this->bits--;
	return (old);
}

bool Fixed::operator<(const Fixed& rhs) const
{
	enum Ordering cmp = this->cmp(rhs);
	return (cmp == LT);
}

bool Fixed::operator>(const Fixed& rhs) const
{
	enum Ordering cmp = this->cmp(rhs);

	return (cmp == GT);
}

bool Fixed::operator==(const Fixed& rhs) const
{
	enum Ordering cmp = this->cmp(rhs);

	return (cmp == EQ);
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	enum Ordering cmp = this->cmp(rhs);

	return (cmp != EQ);
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	enum Ordering cmp = this->cmp(rhs);

	return (cmp == EQ || cmp == LT);
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	enum Ordering cmp = this->cmp(rhs);

	return (cmp == EQ || cmp == GT);
}

bool Fixed::operator<(const Fixed& rhs)
{
	enum Ordering cmp = this->cmp(rhs);
	return (cmp == LT);
}

bool Fixed::operator>(const Fixed& rhs)
{
	enum Ordering cmp = this->cmp(rhs);

	return (cmp == GT);
}

bool Fixed::operator==(const Fixed& rhs)
{
	enum Ordering cmp = this->cmp(rhs);

	return (cmp == EQ);
}

bool Fixed::operator!=(const Fixed& rhs)
{
	enum Ordering cmp = this->cmp(rhs);

	return (cmp != EQ);
}

bool Fixed::operator<=(const Fixed& rhs)
{
	enum Ordering cmp = this->cmp(rhs);

	return (cmp == EQ || cmp == LT);
}

bool Fixed::operator>=(const Fixed& rhs)
{
	enum Ordering cmp = this->cmp(rhs);

	return (cmp == EQ || cmp == GT);
}

Fixed Fixed::operator+(Fixed rhs)
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed rhs)
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed rhs)
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed rhs)
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

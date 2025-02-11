/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:48:34 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/19 22:53:54 by maiboyer         ###   ########.fr       */
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

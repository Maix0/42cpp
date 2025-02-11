/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:48:34 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/19 22:16:16 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

const int Fixed::fractionBitsWidth = 8;

Fixed::~Fixed() {};

Fixed::Fixed()
{
	this->bits = 0;
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

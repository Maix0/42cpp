/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:48:21 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/19 23:25:36 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>
enum Ordering
{
	LT = 1 << 0,
	EQ = 1 << 1,
	GT = 1 << 2,
};

class Fixed
{
public:
	Fixed();
	Fixed(int);
	Fixed(float);
	~Fixed();
	Fixed(const Fixed& rhs);
	Fixed& operator=(const Fixed& rhs);

	int	 getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int	  toInt(void) const;

	static Fixed&		min(Fixed& lhs, Fixed& rhs);
	static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
	static Fixed&		max(Fixed& lhs, Fixed& rhs);
	static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

	bool operator<(const Fixed& rhs);
	bool operator>(const Fixed& rhs);
	bool operator==(const Fixed& rhs);
	bool operator!=(const Fixed& rhs);
	bool operator<=(const Fixed& rhs);
	bool operator>=(const Fixed& rhs);
	bool operator<(const Fixed& rhs) const;
	bool operator>(const Fixed& rhs) const;
	bool operator==(const Fixed& rhs) const;
	bool operator!=(const Fixed& rhs) const;
	bool operator<=(const Fixed& rhs) const;
	bool operator>=(const Fixed& rhs) const;

	Fixed& operator++();
	Fixed  operator++(int);
	Fixed& operator--();
	Fixed  operator--(int);

	Fixed operator+(Fixed rhs);
	Fixed operator-(Fixed rhs);
	Fixed operator*(Fixed rhs);
	Fixed operator/(Fixed rhs);

private:
	int				 bits;
	static const int fractionBitsWidth;

	enum Ordering cmp(const Fixed& rhs) const;
};

std::ostream& operator<<(std::ostream& o, const Fixed& rhs);

#endif /* FIXED_HPP */

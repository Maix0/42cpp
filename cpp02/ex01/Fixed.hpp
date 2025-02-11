/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:48:21 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/19 22:31:00 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>
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

private:
	int				 bits;
	static const int fractionBitsWidth;
};

std::ostream& operator<<(std::ostream& o, const Fixed& rhs);

#endif /* FIXED_HPP */

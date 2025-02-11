/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:48:21 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/19 22:10:12 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& rhs);
	Fixed& operator=(const Fixed& rhs);

	int	 getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int				 bits;
	static const int fractionBitsWidth;
};

#endif /* FIXED_HPP */

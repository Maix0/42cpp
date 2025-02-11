/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:48:26 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/09 15:17:36 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

#include <bitset>
#include <climits>
#include <iostream>
int main(void)
{
	Fixed		a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "max " << Fixed(INT_MAX) << std::endl;
	std::cout << "min " << Fixed(INT_MIN) << std::endl;
	std::cout << "overflow " << Fixed((float)(INT_MAX) + 1.f) << std::endl;
	std::cout << "overflow " << Fixed((float)(INT_MIN) - 1.f) << std::endl;

	std::cout << "[int]max " << Fixed(INT_MAX).toInt() << std::endl;
	std::cout << "[int]min " << Fixed(INT_MIN).toInt() << std::endl;
	std::cout << "[int]overflow " << Fixed((float)(INT_MAX) + 1.f).toInt()
			  << std::endl;
	std::cout << "[int]overflow " << Fixed((float)(INT_MIN) - 1.f).toInt()
			  << std::endl;
	return 0;
}

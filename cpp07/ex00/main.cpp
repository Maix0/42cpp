/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:13:57 by maiboyer          #+#    #+#             */
/*   Updated: 2024/12/27 17:58:27 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include <iostream>

#define TEST_MAX(lhs, rhs)                                                                                             \
	do                                                                                                                 \
	{                                                                                                                  \
		std::cout << "max(" << lhs << ", " << rhs << ") = " << ::max(lhs, rhs) << std::endl;                             \
	} while (0)

#define TEST_MIN(lhs, rhs)                                                                                             \
	do                                                                                                                 \
	{                                                                                                                  \
		std::cout << "min(" << lhs << ", " << rhs << ") = " << ::min(lhs, rhs) << std::endl;                             \
	} while (0)

#define TEST_SWAP(type, lhs, rhs)                                                                                      \
	do                                                                                                                 \
	{                                                                                                                  \
		type left = lhs;                                                                                               \
		type right = rhs;                                                                                              \
		std::cout << "Before: left=" << left << "; Right=" << right << ";" << std::endl;                               \
		::swap(left, right);                                                                                             \
		std::cout << "After : left=" << left << "; Right=" << right << ";" << std::endl;                               \
		std::cout << std::endl;                                                                                        \
	} while (0)

int main()
{
	TEST_MAX((int)1, (int)127);
	TEST_MAX((char)'a', (char)'A');
	TEST_MAX((unsigned int)-1, (unsigned int)198);
	std::cout << std::endl;

	TEST_MIN((int)1, (int)127);
	TEST_MIN((char)'a', (char)'A');
	TEST_MIN((unsigned int)-1, (unsigned int)198);
	std::cout << std::endl;

	TEST_SWAP(int, 1, 0);
	TEST_SWAP(char, 'a', 'b');
	TEST_SWAP(std::string, "left string here", "right string here");
}

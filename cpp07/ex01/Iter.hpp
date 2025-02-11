/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:47:50 by maiboyer          #+#    #+#             */
/*   Updated: 2025/01/06 16:03:34 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T> void iter(T arr[], size_t len, void (*func)(T elem))
{
	if (func == NULL)
	{
		std::cerr << "Function was null" << std::endl;
		return;
	}
	if (arr == NULL)
	{
		std::cerr << "Array was null" << std::endl;
		return;
	}
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif /* ITER_HPP */

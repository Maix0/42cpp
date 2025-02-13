/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:17:08 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/11 16:50:22 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstddef>
#include <iostream>

int main()
{
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	{
		Span cpy(sp);
		for (size_t i = 0; i < cpy.size(); i++)
			std::cout << "Copy[" << i << "] = " << cpy[i] << std::endl; 
		for (size_t i = 0; i < sp.size(); i++)
			std::cout << "Base[" << i << "] = " << sp[i] << std::endl; 
	}

	return 0;
}
